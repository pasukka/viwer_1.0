#include "settings.h"

void Settings::setProjectionType(v_settings_projection_types type) {
  projection_type = type;
};

v_settings_projection_types Settings::getProjectionType() {
  return projection_type;
}

void Settings::setLineType(v_settings_line_types type) {
  line_type = type;
};

v_settings_line_types Settings::getLineType() { return line_type; }

void Settings::setLineWidth(float width) { line_width = width; };

float Settings::getLineWidth() { return line_width; }

void Settings::setVertexSize(float size) { vertex_size = size; };

float Settings::getVertexSize() { return vertex_size; }

void Settings::setBackgroundColorR(float color) {
  background_color.r() = color;
};

void Settings::setBackgroundColorG(float color) {
  background_color.g() = color;
};

void Settings::setBackgroundColorB(float color) {
  background_color.b() = color;
};

Vector3 Settings::getBackgroundColor() { return background_color; }

void Settings::setLineColorR(float color) { line_color.r() = color; };

void Settings::setLineColorG(float color) { line_color.r() = color; };

void Settings::setLineColorB(float color) { line_color.r() = color; };

Vector3 Settings::getLineColor() { return line_color; }

void Settings::setVerticesColorR(float color) {
  vertices_color.r() = color;
};

void Settings::setVerticesColorG(float color) {
  vertices_color.g() = color;
};

void Settings::setVerticesColorB(float color) {
  vertices_color.b() = color;
};

Vector3 Settings::getVerticesColor() { return vertices_color; }

v_settings_error_codes Settings::getError() { return error_code; }

void Settings::setError(v_settings_error_codes code) { error_code = code; }

void Settings::clearError() { error_code = v_settings_OK; }

void Settings::setDisplayType(v_settings_vertex_display_types type) {
  display_type = type;
};

v_settings_vertex_display_types Settings::getDisplayType() {
  return display_type;
}

void Settings::uploadSettings(const std::string& settings_file_path) {
  FILE* input = fopen(settings_file_path.c_str(), "rb");
  if (input != NULL) {
    Settings tempSettings;
    if (fread(&tempSettings, sizeof(Settings), 1, input) >= 1) {
      *this = tempSettings;
    }
    fclose(input);
  } else {
    initSettings();
  }
}

void Settings::saveSettings(const std::string& settings_file_path) {
  FILE* output = fopen(settings_file_path.c_str(), "wb");
  if (output != NULL) {
    fwrite(this, sizeof(*this), 1, output);
    fclose(output);
  } else {
    error_code = v_settings_CANT_WRITE;
  }
}

void Settings::initSettings() {
  error_code = v_settings_OK;
  Vector3 bc;
  bc.r() = 79 / 255.0f;
  bc.g() = 33 / 255.0f;
  bc.b() = 176 / 255.0f;

  background_color = bc;
  Vector3 lc;
  lc.r() = 1.0f;
  lc.g() = 1.0f;
  lc.b() = 1.0f;

  line_color = lc;
  Vector3 vertices3d_color;
  vertices3d_color.r() = 1.0f;
  vertices3d_color.g() = 1.0f;
  vertices3d_color.b() = 1.0f;

  vertices_color = vertices3d_color;
  line_width = 2.0f;
  line_type = v_settings_line_solid;
  vertex_size = 3.0f;
  display_type = v_settings_vertex_display_circle;
  projection_type = v_settings_projection_parallel;
}
