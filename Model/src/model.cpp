#include "model.h"

Model::Model(IParser* p)
    : parser(p),
      file_path(""),
      vertices3d(NULL),
      vertices4d(NULL),
      vertices_count(0),
      indices(NULL),
      indices_count(0),
      error_code(0) {
  parser->initParser(this);
}

size_t Model::getVerticesCount() { return vertices_count; }

void Model::setVerticesCount(size_t count) { vertices_count = count; }

size_t Model::getIndicesCount() { return indices_count; }

void Model::setIndicesCount(size_t count) { indices_count = count; }

void Model::setFilePath(std::string path) { file_path = path; }

const std::string& Model::getFilePath() const { return file_path; }

void Model::setErrorCode(int error) { error_code = error; }

int Model::getErrorCode() { return error_code; }

Vector3* Model::getVertices3d() { return vertices3d; }

void Model::setVertices3d(Vector3* vertices) { vertices3d = vertices; }

Vector4* Model::getVertices4d() { return vertices4d; }

void Model::setVertices4d(Vector4* vertices) { vertices4d = vertices; }

unsigned int* Model::getIndices() { return indices; }

void Model::setIndices(unsigned int* indices) { this->indices = indices; }

void Model::uploadModel(std::string file_path) {
  setFilePath(file_path);
  parser->parseFile();
}

void Model::initModel() {
  if (error_code == 0) {
    normalizeModel();
  }
  if (error_code == 0) {
    generate4dFrom3d();
  }
}

void Model::normalizeModel() {
  float max_x, min_x;
  max_x = min_x = vertices3d[0].x();
  float max_y, min_y;
  max_y = min_y = vertices3d[0].y();
  float max_z, min_z;
  max_z = min_z = vertices3d[0].z();

  for (size_t i = 1; i < vertices_count; ++i) {
    max_x = std::max(max_x, vertices3d[i].x());
    min_x = std::min(min_x, vertices3d[i].x());
    max_y = std::max(max_y, vertices3d[i].y());
    min_y = std::min(min_y, vertices3d[i].y());
    max_z = std::max(max_z, vertices3d[i].z());
    min_z = std::min(min_z, vertices3d[i].z());
  }
  float all_max = std::max(std::max(max_x, max_y), max_z);
  float all_min = std::min(std::min(min_x, min_y), min_z);
  float all_max_abs = std::max(fabsf(all_max), fabsf(all_min));
  // first centralize then normalize(-1 .. 1) then make slightly smaller
  for (size_t i = 0; i < vertices_count && all_max_abs > 1; ++i) {
    vertices3d[i].x() = vertices3d[i].x() - (max_x + min_x) / 2;
    vertices3d[i].x() /= all_max_abs;
    vertices3d[i].x() *= MINIMIZE_FACTOR;
    vertices3d[i].y() = vertices3d[i].y() - (max_y + min_y) / 2;
    vertices3d[i].y() /= all_max_abs;
    vertices3d[i].y() *= MINIMIZE_FACTOR;
    vertices3d[i].z() = vertices3d[i].z() - (max_z + min_z) / 2;
    vertices3d[i].z() /= all_max_abs;
    vertices3d[i].z() *= MINIMIZE_FACTOR;
  }
}

void Model::generate4dFrom3d() {
  vertices4d = new Vector4[vertices_count];
  for (size_t i = 0; i < vertices_count; ++i) {
    vertices4d[i] = get4dBy3d(vertices3d[i]);
  }
}

Vector4 Model::get4dBy3d(Vector3 vector) {
  Vector4 result;
  result.x() = vector.x();
  result.y() = vector.y();
  result.z() = vector.z();
  result.w() = 1.0f;
  return result;
}

void Model::deleteModel() {
  if (indices) {
    delete[] indices;
    indices = NULL;
  }
  if (vertices3d != NULL) {
    delete[] vertices3d;
    vertices3d = NULL;
  };
  if (vertices4d != NULL) {
    delete[] vertices4d;
    vertices4d = NULL;
  };
}
