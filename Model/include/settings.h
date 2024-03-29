#if !defined(SRC_MODEL_INCLUDE_SETTINGS_H)
#define SRC_MODEL_INCLUDE_SETTINGS_H

/**
 * @file settings.h
 * @author SevenStreams
 * @brief This file handles working with settings
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "interface_settings.h"
#include "matrix_generator.h"

class Settings : public ISettings {
 public:
  /**
   * @brief The function extracts settings from a file
   *
   * @param settings_file_path The settings file path
   * @return v_settings The settings object
   */
  void uploadSettings(const std::string &settings_file_path) override;

  /**
   * @brief The function saves settings into a file
   *
   * @param settings_file_path The settings file path
   */
  void saveSettings(const std::string &settings_file_path) override;

  /**
   * @brief The function initializing settings
   *
   * @param settings The settings object
   */
  void initSettings() override;

  /**
   * @brief Initializes the settings by calling the initSettings function.
   */
  Settings() { initSettings(); }

  /**
   * @brief Set the projection type in the settings
   *
   * @param type The projection type to be set
   */
  void setProjectionType(v_settings_projection_types type);

  /**
   * @brief Get the projection type from the settings
   *
   * @return v_settings_projection_types The projection type
   */
  v_settings_projection_types getProjectionType();

  /**
   * @brief Set the line type in the settings
   *
   * @param type The line type to be set
   */
  void setLineType(v_settings_line_types type);

  /**
   * @brief Get the line type from the settings
   *
   * @return v_settings_line_types The line type
   */
  v_settings_line_types getLineType();

  /**
   * @brief Set the line width in the settings
   *
   * @param width The line width to be set
   */
  void setLineWidth(float width);

  /**
   * @brief Get the line width from the settings
   *
   * @return float The line width
   */
  float getLineWidth();

  /**
   * @brief Set the vertex size in the settings
   *
   * @param size The vertex size to be set
   */
  void setVertexSize(float size);

  /**
   * @brief Get the vertex size from the settings
   *
   * @return float The vertex size
   */
  float getVertexSize();

  /**
   * @brief Set the red component of the background color in the settings
   *
   * @param color The red component of the background color to be set
   */
  void setBackgroundColorR(float color);

  /**
   * @brief Set the green component of the background color in the settings
   *
   * @param color The green component of the background color to be set
   */
  void setBackgroundColorG(float color);

  /**
   * @brief Set the blue component of the background color in the settings
   *
   * @param color The blue component of the background color to be set
   */
  void setBackgroundColorB(float color);

  /**
   * @brief Get the background color from the settings
   *
   * @return Vector3 The background color
   */
  Vector3 getBackgroundColor();

  /**
   * @brief Set the red component of the line color in the settings
   *
   * @param color The red component of the line color to be set
   */
  void setLineColorR(float color);

  /**
   * @brief Set the green component of the line color in the settings
   *
   * @param color The green component of the line color to be set
   */
  void setLineColorG(float color);

  /**
   * @brief Set the blue component of the line color in the settings
   *
   * @param color The blue component of the line color to be set
   */
  void setLineColorB(float color);

  /**
   * @brief Get the line color from the settings
   *
   * @return Vector3 The line color
   */
  Vector3 getLineColor();

  /**
   * @brief Set the red component of the vertices color in the settings
   *
   * @param color The red component of the vertices color to be set
   */
  void setVerticesColorR(float color);
  /**
   * @brief Set the green component of the vertices color in the settings
   *
   * @param color The green component of the vertices color to be set
   */
  void setVerticesColorG(float color);

  /**
   * @brief Set the blue component of the vertices color in the settings
   *
   * @param color The blue component of the vertices color to be set
   */
  void setVerticesColorB(float color);

  /**
   * @brief Get the vertices color from the settings
   *
   * @return Vector3 The vertices color
   */
  Vector3 getVerticesColor();

  /**
   * @brief Get the error code from the settings
   *
   * @return v_settings_error_codes The error code
   */
  v_settings_error_codes getError();

  /**
   * @brief Sets the error code for the Settings object.
   *
   * @param code The error code to set.
   */
  void setError(v_settings_error_codes code);

  /**
   * @brief Clears the error code for the Settings object.
   */
  void clearError();

  /**
   * @brief Sets the display type for the Settings object.
   *
   * @param type The display type to set.
   */
  void setDisplayType(v_settings_vertex_display_types type);
  /**
   * @brief Gets the display type for the Settings object.
   *
   * @return The current display type.
   */
  v_settings_vertex_display_types getDisplayType();

 private:
  /**
   * @brief Settings structure
   *
   */
  v_settings_vertex_display_types display_type;
  v_settings_projection_types projection_type;
  v_settings_line_types line_type;
  float line_width;
  float vertex_size;
  Vector3 background_color;
  Vector3 line_color;
  Vector3 vertices_color;
  v_settings_error_codes error_code;  // if 0 -- there are no errors yet
};

#endif  // SRC_MODEL_INCLUDE_SETTINGS_H
