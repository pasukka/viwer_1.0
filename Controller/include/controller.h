#ifndef SRC_CONTROLLER_INCLUDE_CONTROLLER_H
#define SRC_CONTROLLER_INCLUDE_CONTROLLER_H

/**
 * @file controller.h
 * @author SevenStreams
 * @brief This file handles working with controller, which connects Model and
 * View
 * @version 0.1
 * @date 2024-03-09
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <string>

#include "matrix_generator.h"
#include "model.h"
#include "parser.h"
#include "settings.h"
#include "settings_path.h"

/**
 * @brief The controller class
 */
class Controller {
 private:
  Model *model;
  Settings *settings;
  const std::string settings_path = SETTINGS_PATH;
  bool ModelInitialized_ = false;
  Vector4 *vertices_copy_ = nullptr;
  Matrix4x4 view_matrix_;
  Matrix4x4 projection_matrix_;
  Vector3 rotation_angles_;
  Vector3 translation_vector_;
  float scale_;
  int error;

 public:
  using string = std::string;
  /**
   * @brief The function handles initializing controller
   *
   * @param m The model
   * @return Controller The controller
   */
  Controller(Model *m, Settings *s) : model(m), settings(s), error(0){};

  /**
   * @brief The function handles destroying controller
   *
   */
  ~Controller();

  /**
   * @brief The function handles uploading model
   *
   * @param fileName The path to model
   * @return int The error code
   */
  int uploadModel(std::string fileName);

  /**
   * @brief The function handles setting model
   *
   */
  void setModel();

  /**
   * @brief The function handles updating model
   *
   */
  void updateModel();

  /**
   * @brief The function returns if model initialized
   *
   * @return bool Returns true if model initialized
   */
  bool getModelInitialized();

  /**
   * @brief The function sets model matrix
   *
   */
  void setModelMatrixes();

  /**
   * @brief The function resets model state
   *
   */
  void resetState();

  /**
   * @brief The function returns number of vertices
   *
   * @return int Number of vertices
   */
  int getVerticesCount();

  /**
   * @brief The function returns number of edges
   *
   * @return int Number of edges
   */
  int getEdgesNumber();

  /**
   * @brief The function convert error code to human-readable form
   *
   * @param error The error code
   * @return string Error
   */
  string errorHandler(int error);

  /**
   * @brief The function returns rotation x
   *
   * @return float Rotation x
   */
  float getRotationAnglesX();

  /**
   * @brief The function returns rotation y
   *
   * @return float Rotation y
   */
  float getRotationAnglesY();

  /**
   * @brief The function returns rotation z
   *
   * @return float Rotation z
   */
  float getRotationAnglesZ();

  /**
   * @brief The function returns translation x
   *
   * @return float Translation x
   */
  float getTranslationVectorX();

  /**
   * @brief The function returns translation y
   *
   * @return float Translation y
   */
  float getTranslationVectorY();

  /**
   * @brief The function returns translation z
   *
   * @return float Translation z
   */
  float getTranslationVectorZ();

  /**
   * @brief The function sets translation x
   *
   * @param x Translation x
   */
  void setTranslationVectorX(float x);

  /**
   * @brief The function sets translation y
   *
   * @param y Translation y
   */
  void setTranslationVectorY(float y);

  /**
   * @brief The function sets translation z
   *
   * @param z Translation z
   */
  void setTranslationVectorZ(float z);

  /**
   * @brief The function sets rotation x
   *
   * @param x Rotation x
   */
  void setRotationAnglesX(float x);

  /**
   * @brief The function sets rotation y
   *
   * @param y Rotation y
   */
  void setRotationAnglesY(float y);

  /**
   * @brief The function sets rotation z
   *
   * @param z Rotation z
   */
  void setRotationAnglesZ(float z);

  /**
   * @brief The function sets rotation x
   *
   * @param scale Rotation x
   */
  void setScale(float scale);

  /**
   * @brief The function gets model scale
   *
   * @return float cale
   */
  float getScale();

  /**
   * @brief The function returns index of line type
   *
   * @return int Index of line type
   */
  int getLineTypeIndex();

  /**
   * @brief The function returns index of display type
   *
   * @return int Index of display type
   */
  int getDisplayTypeIndex();

  /**
   * @brief The function returns index of projection type
   *
   * @return int Index of projection type
   */
  int getProjectionTypeIndex();

  /**
   * @brief The function returns if line should be stippled
   *
   * @return bool True if line should be stippled
   */
  bool toStipple();

  /**
   * @brief The function returns if edge should have smooth transition
   *
   * @return bool True if edge should smooth
   */
  bool toSmooth();

  /**
   * @brief The function returns if edge should be colored
   *
   * @return bool True if edge should be colored
   */
  bool toColor();

  /**
   * @brief The function uploads settings
   *
   */
  void uploadSettings();

  /**
   * @brief The function handles saving settings to file
   *
   */
  void saveSettings();

  /**
   * @brief The function sets projection type
   *
   * @param index The index
   */
  void setProjectionType(int index);

  /**
   * @brief The function returns projection type
   *
   * @return Projection type
   */
  v_settings_projection_types getProjectionType();

  /**
   * @brief The function sets line type
   *
   * @param index The index
   */
  void setLineType(int index);

  /**
   * @brief The function returns line type
   *
   * @return Line type
   */
  v_settings_line_types getLineType();

  /**
   * @brief The function sets line width
   *
   * @param width The width
   */
  void setLineWidth(float width);

  /**
   * @brief The function returns line width
   *
   * @return float Line width
   */
  float getLineWidth();

  /**
   * @brief The function sets vertex size
   *
   * @param size The size
   */
  void setVertexSize(float size);

  /**
   * @brief The function returns vertex size
   *
   * @return float Vertex size
   */
  float getVertexSize();

  /**
   * @brief The function sets background color (red)
   *
   * @param color The color red
   */
  void setBackgroundColorR(float color);

  /**
   * @brief The function sets background color (green)
   *
   * @param color The color green
   */
  void setBackgroundColorG(float color);

  /**
   * @brief The function sets background color (blue)
   *
   * @param color The color blue
   */
  void setBackgroundColorB(float color);

  /**
   * @brief The function returns background color
   *
   * @return v_vectorf3d Background color vector
   */
  Vector3 getBackgroundColor();

  /**
   * @brief The function sets line color (red)
   *
   * @param color The color red
   */
  void setLineColorR(float color);

  /**
   * @brief The function sets line color (green)
   *
   * @param color The color green
   */
  void setLineColorG(float color);

  /**
   * @brief The function sets line color (blue)
   *
   * @param color The color blue
   */
  void setLineColorB(float color);

  /**
   * @brief The function returns line color
   *
   * @return v_vectorf3d Line color vector
   */
  Vector3 getLineColor();

  /**
   * @brief The function sets vertices color (red)
   *
   * @param color The color red
   */
  void setVerticesColorR(float color);

  /**
   * @brief The function sets vertices color (green)
   *
   * @param color The color green
   */
  void setVerticesColorG(float color);

  /**
   * @brief The function sets vertices color (blue)
   *
   * @param color The color blue
   */
  void setVerticesColorB(float color);

  /**
   * @brief The function returns vertices color
   *
   * @return v_vectorf3d Vertices color vector
   */
  Vector3 getVerticesColor();

  /**
   * @brief The function returns error code
   *
   * @return Error code
   */
  v_settings_error_codes getError();

  /**
   * @brief The function sets error code
   *
   * @param code The error code
   */
  void setError(v_settings_error_codes code);

  /**
   * @brief The function clears error
   *
   */
  void clearError();

  /**
   * @brief The function sets display type
   *
   * @param index The index
   */
  void setDisplayType(int index);

  /**
   * @brief The function returns display type
   *
   * @return Display type
   */
  v_settings_vertex_display_types getDisplayType();

  int getIndicesCount();
  unsigned int *getIndices();

  /**
   * @brief The function returns vertices
   *
   * @return Vertices vector
   */
  Vector4 *getVerticesCopy();

  /**
   * @brief The function returns compiled model matrix
   *
   * @return Model matrix
   */
  Matrix4x4 compileModelMatrix();
};

#endif  // SRC_CONTROLLER_INCLUDE_CONTROLLER_H
