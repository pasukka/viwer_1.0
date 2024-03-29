#if !defined(SRC_MODEL_INCLUDE_INTERFACE_SETTINGS_H)
#define SRC_MODEL_INCLUDE_INTERFACE_SETTINGS_H

/**
 * @file interface_settings.h
 * @author SevenStreams
 * @brief This file handles interface of settings
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <string>

/**
 * @brief Error codes for settings
 *
 */
typedef enum e_settings_error_codes {
  v_settings_OK,
  v_settings_CANT_WRITE
} v_settings_error_codes;

/**
 * @brief Line types for settings
 *
 */
typedef enum e_settings_line_types {
  v_settings_line_dotted,
  v_settings_line_solid
} v_settings_line_types;

/**
 * @brief Projection types for settings
 *
 */
typedef enum e_settings_projection_types {
  v_settings_projection_parallel,
  v_settings_projection_central
} v_settings_projection_types;

/**
 * @brief Vertex display types for settings
 *
 */
typedef enum e_settings_vertex_display_types {
  v_settings_vertex_display_no,
  v_settings_vertex_display_circle,
  v_settings_vertex_display_square
} v_settings_vertex_display_types;

/**
 * @class ISettings
 * @brief Interface for handling settings.
 *
 * This class defines an interface for handling settings. It provides methods to
 * upload, save, and initialize settings.
 *
 * @note All methods in this class are pure virtual, meaning any class that
 * inherits from this interface must implement these methods.
 */
class ISettings {
 public:
  virtual ~ISettings() {}

  /**
   * @brief Uploads settings from a file.
   *
   * This function is responsible for uploading settings from a file.
   *
   * @param settings_file_path The path to the settings file.
   */
  virtual void uploadSettings(const std::string &settings_file_path) = 0;

  /**
   * @brief Saves settings to a file.
   *
   * This function is responsible for saving settings to a file.
   *
   * @param settings_file_path The path to the settings file.
   */
  virtual void saveSettings(const std::string &settings_file_path) = 0;

  /**
   * @brief Initializes settings.
   *
   * This function is responsible for initializing settings.
   */
  virtual void initSettings() = 0;
};


#endif  // SRC_MODEL_INCLUDE_INTERFACE_SETTINGS_H
