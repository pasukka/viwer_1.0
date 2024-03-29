#include "controller.h"

Controller::~Controller() {
  if (vertices_copy_ != nullptr) {
    delete[] vertices_copy_;
  }
  model->deleteModel();
}

void Controller::setModelMatrixes() {
  if (settings->getProjectionType() == v_settings_projection_central) {
    projection_matrix_ = MatrixGenerator().generate_identity();
    view_matrix_ = MatrixGenerator().generate_identity();
  } else if (settings->getProjectionType() == v_settings_projection_parallel) {
    projection_matrix_ = MatrixGenerator().generate_frustrum_matrix(
        -0.065, 0.065, -0.065, 0.065, 0.1, 2.0);
    view_matrix_ =
        MatrixGenerator().generate_translation_matrix({0.0f, 0.0f, -1.0f});
  }
}

int Controller::uploadModel(std::string fileName) {
  model->deleteModel();
  model->uploadModel(fileName);
  model->initModel();
  settings->uploadSettings(settings_path);
  error = model->getErrorCode();
  if (error) ModelInitialized_ = false;
  return error;
}

void Controller::resetState() {
  scale_ = 1.0f;
  rotation_angles_.x() = 0.0f;
  rotation_angles_.y() = 0.0f;
  rotation_angles_.z() = 0.0f;
  translation_vector_.x() = 0.0f;
  translation_vector_.y() = 0.0f;
  translation_vector_.z() = 0.0f;
}

void Controller::setTranslationVectorX(float x) {
  translation_vector_.x() = x;
}

void Controller::setTranslationVectorY(float y) {
  translation_vector_.y() = y;
}

void Controller::setTranslationVectorZ(float z) {
  translation_vector_.z() = z;
}

float Controller::getTranslationVectorX() {
  return translation_vector_.x();
}

float Controller::getTranslationVectorY() {
  return translation_vector_.y();
}

float Controller::getTranslationVectorZ() {
  return translation_vector_.z();
}

void Controller::setRotationAnglesX(float x) { rotation_angles_.x() = x; }

void Controller::setRotationAnglesY(float y) { rotation_angles_.y() = y; }

void Controller::setRotationAnglesZ(float z) { rotation_angles_.z() = z; }

float Controller::getRotationAnglesX() { return rotation_angles_.x(); }

float Controller::getRotationAnglesY() { return rotation_angles_.y(); }

float Controller::getRotationAnglesZ() { return rotation_angles_.z(); }

void Controller::setScale(float scale) { scale_ = scale; }

float Controller::getScale() { return scale_; }

Controller::string Controller::errorHandler(int error) {
  string s = "Error";
  if (error == ERROR) {
    s += " while loading model.";
  } else if (error == ERROR_FILE) {
    s += " while opening file.";
  } else if (error == ERROR_V) {
    s += ". Wrong number of vertices.";
  } else if (error == ERROR_F) {
    s += ". Wrong number of indexes.";
  } else if (error == EMPTY_FILE) {
    s += ". Empty file.";
  }
  return s;
}

bool Controller::getModelInitialized() { return ModelInitialized_; }

int Controller::getVerticesCount() { return model->getVerticesCount(); }

int Controller::getEdgesNumber() { return model->getIndicesCount() * 3; }

int Controller::getIndicesCount() { return model->getIndicesCount(); }
unsigned int *Controller::getIndices() { return model->getIndices(); }

void Controller::setModel() {
  ModelInitialized_ = true;
  if (vertices_copy_ != nullptr) {
    delete[] vertices_copy_;
  }
  vertices_copy_ = new Vector4[model->getVerticesCount()];
}

void Controller::updateModel() {
  Matrix4x4 result_matrix =
      MatrixGenerator().matrix_mult_4x4(view_matrix_, compileModelMatrix());
  result_matrix =
      MatrixGenerator().matrix_mult_4x4(projection_matrix_, result_matrix);
  if (ModelInitialized_) {
    MatrixGenerator().f4d_vertex_array_processing(
        model->getVertices4d(), vertices_copy_, model->getVerticesCount(),
        result_matrix);
  }
}

Vector4 *Controller::getVerticesCopy() { return vertices_copy_; }

Matrix4x4 Controller::compileModelMatrix() {
  Matrix4x4 matrix = MatrixGenerator().generate_XYZaxis_rotation_matrix(
      rotation_angles_.y(), rotation_angles_.x(), rotation_angles_.z());
  matrix = MatrixGenerator().matrix_mult_4x4(
      matrix, MatrixGenerator().generate_scale_matrix(scale_, scale_, scale_));
  matrix = MatrixGenerator().matrix_mult_4x4(
      matrix,
      MatrixGenerator().generate_translation_matrix(translation_vector_));
  return matrix;
}

void Controller::uploadSettings() {
  settings->uploadSettings(SETTINGS_PATH);
}

void Controller::saveSettings() { settings->saveSettings(SETTINGS_PATH); }

void Controller::setProjectionType(int index) {
  if (index == 0) {
    settings->setProjectionType(v_settings_projection_parallel);
  } else if (index == 1) {
    settings->setProjectionType(v_settings_projection_central);
  }
};

int Controller::getProjectionTypeIndex() {
  int output = 0;  // v_settings_projection_parallel
  if (settings->getProjectionType() == v_settings_projection_central) {
    output = 1;
  }
  return output;
};

v_settings_projection_types Controller::getProjectionType() {
  return settings->getProjectionType();
}

void Controller::setLineType(int index) {
  if (index == 0) {
    settings->setLineType(v_settings_line_solid);
  } else if (index == 1) {
    settings->setLineType(v_settings_line_dotted);
  }
};

int Controller::getLineTypeIndex() {
  int output = 0;  // v_settings_line_solid
  if (settings->getLineType() == v_settings_line_dotted) {
    output = 1;
  }
  return output;
}

v_settings_line_types Controller::getLineType() {
  return settings->getLineType();
}

void Controller::setDisplayType(int index) {
  if (index == 0) {
    settings->setDisplayType(v_settings_vertex_display_no);
  } else if (index == 1) {
    settings->setDisplayType(v_settings_vertex_display_circle);
  } else if (index == 2) {
    settings->setDisplayType(v_settings_vertex_display_square);
  }
};

int Controller::getDisplayTypeIndex() {
  int output = 0;  // v_settings_vertex_display_no
  if (settings->getDisplayType() == v_settings_vertex_display_circle) {
    output = 1;
  } else if (settings->getDisplayType() == v_settings_vertex_display_square) {
    output = 2;
  }
  return output;
};

v_settings_vertex_display_types Controller::getDisplayType() {
  return settings->getDisplayType();
}

void Controller::setLineWidth(float width) {
  settings->setLineWidth(width);
};

float Controller::getLineWidth() { return settings->getLineWidth(); }

void Controller::setVertexSize(float size) {
  settings->setVertexSize(size);
};

float Controller::getVertexSize() { return settings->getVertexSize(); }

void Controller::setBackgroundColorR(float color) {
  settings->setBackgroundColorR(color);
};

void Controller::setBackgroundColorG(float color) {
  settings->setBackgroundColorG(color);
};

void Controller::setBackgroundColorB(float color) {
  settings->setBackgroundColorB(color);
};

Vector3 Controller::getBackgroundColor() {
  return settings->getBackgroundColor();
}

void Controller::setLineColorR(float color) {
  settings->setLineColorR(color);
};

void Controller::setLineColorG(float color) {
  settings->setLineColorG(color);
};

void Controller::setLineColorB(float color) {
  settings->setLineColorB(color);
};

Vector3 Controller::getLineColor() {
  return settings->getLineColor();
}

void Controller::setVerticesColorR(float color) {
  settings->setVerticesColorR(color);
};

void Controller::setVerticesColorG(float color) {
  settings->setVerticesColorG(color);
};

void Controller::setVerticesColorB(float color) {
  settings->setVerticesColorB(color);
};

Vector3 Controller::getVerticesColor() {
  return settings->getVerticesColor();
}

v_settings_error_codes Controller::getError() {
  return settings->getError();
}

void Controller::setError(v_settings_error_codes code) {
  settings->setError(code);
}

void Controller::clearError() { settings->clearError(); }

bool Controller::toStipple() {
  bool output = true;
  if (settings->getLineType() == v_settings_line_solid) {
    output = false;
  }
  return output;
}

bool Controller::toSmooth() {
  bool output = true;
  if (settings->getDisplayType() == v_settings_vertex_display_square) {
    output = false;
  }
  return output;
}

bool Controller::toColor() {
  bool output = true;
  if (settings->getDisplayType() == v_settings_vertex_display_no) {
    output = false;
  }
  return output;
}
