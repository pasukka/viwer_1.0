#include "parser.h"

void Parser::initParser(Model *m) { model = m; }

void Parser::clearVectors() {
  vertexes.clear();
  vertex_indexes.clear();
}

int Parser::addToVector(const std::string &str) {
  int error = OK;
  int number_count = 0;
  std::istringstream ss(str);
  std::string part;
  std::getline(ss, part, SEP);
  while (std::getline(ss, part, SEP) && !error) {
    if (!part.empty() && str[0] == VECTOR) {
      char *endptr;
      double number = std::strtod(part.c_str(), &endptr);
      if (*endptr == '\0' || *endptr == '\n' || *endptr == '\r') {
        vertexes.push_back(number);
        ++number_count;
      } else {
        error = ERROR_V;
      }
    }
  }
  if (number_count < 3) {
    error = ERROR;
  } else if (number_count > 4 && str[0] == VECTOR) {
    error = ERROR_V;
  }
  return error;
}

int Parser::parseFace(const std::string &str) {
  std::string str_copy = str;
  int error_status = 0;
  std::string::size_type i = 1;
  int state = 2;
  int number_start = 0;
  int number = 0;
  int first_index = 0;
  int isFirstIndex = 0;
  int last_index = 0;
  int isLastIndex = 0;
  int isNumber = 0;
  while (!error_status && (i < str_copy.size() || i - 1 < str_copy.size())) {
    switch (state) {
      case 1:
        if (!isdigit(str_copy[i]) || str_copy[i] != '-') {
          state = 2;
          if (!isFirstIndex) {
            sscanf(str_copy.substr(number_start).c_str(), "%d", &first_index);
            isFirstIndex = 1;
          } else if (!isLastIndex) {
            sscanf(str_copy.substr(number_start).c_str(), "%d", &last_index);
            isLastIndex = 1;
          } else {
            sscanf(str_copy.substr(number_start).c_str(), "%d", &number);
            vertex_indexes.push_back(first_index);
            vertex_indexes.push_back(last_index);
            vertex_indexes.push_back(number);
            isNumber = 1;
            last_index = number;
          }
          if (error_status) {
            break;
          }
        } else {
          ++i;
        }
        break;
      case 2:
        if (str_copy[i] == ' ') {
          state = 3;
        }
        ++i;
        break;
      case 3:
        if (isdigit(str_copy[i]) || str_copy[i] == '-') {
          state = 1;
          number_start = i;
        }
        ++i;
        break;
    }
  }
  if (!isNumber) {
    error_status = ERROR;
  }
  return error_status;
}

void Parser::vertexesToModel() {
  model->setVerticesCount(vertexes.size() / 3);
  Vector3 *vertices3d = new Vector3[model->getVerticesCount()];
  for (size_t i = 0, j = 0; i < model->getVerticesCount(); ++i) {
    vertices3d[i].x() = vertexes[j++];
    vertices3d[i].y() = vertexes[j++];
    vertices3d[i].z() = vertexes[j++];
  }
  model->setVertices3d(vertices3d);
}

void Parser::indexesToModel() {
  unsigned int *indices = new unsigned int[vertex_indexes.size()];
  if (model->getVerticesCount() < 1) model->setErrorCode(ERROR_V);
  for (size_t i = 0; i < vertex_indexes.size() && !model->getErrorCode(); ++i) {
    int index = (int)vertex_indexes[i];
    if (index > (int)model->getVerticesCount()) {
      index = (index % model->getVerticesCount()) - 1;
    } else if (index > 0) {
      index -= 1;
    } else if (index == 0) {
      model->setErrorCode(ERROR_F);
    }
    if (index < 0) {
      index = model->getVerticesCount() + index;
    }
    indices[i] = (unsigned)index;
  }
  model->setIndices(indices);
  model->setIndicesCount(vertex_indexes.size());
}

int Parser::fileExists(const std::string &filename) {
  int error = OK;
  std::ifstream file(filename);
  if (!file.is_open()) {
    error = ERROR_FILE;
  }
  return error;
}

int Parser::fileEmpty(const std::string &filename) {
  int error = OK;
  std::ifstream file(filename);
  if (!file.is_open()) {
    error = ERROR_FILE;
  }
  if (file.peek() == std::ifstream::traits_type::eof()) {
    error = EMPTY_FILE;
  }
  return error;
}

void Parser::process() {
  model->setErrorCode(OK);
  std::ifstream file(model->getFilePath());
  std::string str;
  if (!file.is_open()) {
    model->setErrorCode(ERROR_FILE);
  }
  while (!model->getErrorCode() && std::getline(file, str)) {
    if (!str.empty()) {
      if (str[0] == VECTOR && str[1] == SPACE) {
        model->setErrorCode(addToVector(str));
      } else if (str[0] == FACE) {
        model->setErrorCode(parseFace(str));
      }
    }
  }
  if (!model->getErrorCode()) {
    vertexesToModel();
    indexesToModel();
  }
  file.close();
  clearVectors();
}

void Parser::parseFile() {
  setlocale(LC_ALL, "C");
  model->setErrorCode(fileExists(model->getFilePath()));
  if (!model->getErrorCode())
    model->setErrorCode(fileEmpty(model->getFilePath()));
  if (!model->getErrorCode()) process();
}
