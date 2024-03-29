#if !defined(SRC_MODEL_INCLUDE_INTERFACE_MODEL_H)
#define SRC_MODEL_INCLUDE_INTERFACE_MODEL_H

/**
 * @file interface_model.h
 * @author SevenStreams
 * @brief This file handles interface of model
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "interface_parser.h"
#include "interface_settings.h"

/**
 * @class IModel
 * @brief Interface for a model.
 *
 * This class defines the interface for a model. It provides methods for
 * initializing, deleting, and uploading the model.
 */
class IModel {
 public:
  virtual ~IModel() {}

  /**
   * @brief Initializes the model.
   *
   * This method initializes the model.
   */
  virtual void initModel() = 0;

  /**
   * @brief Deletes the model.
   *
   * This method deletes the model.
   */
  virtual void deleteModel() = 0;

  /**
   * @brief Uploads the model from a file.
   *
   * @param file_path The path to the file containing the model.
   *
   * This method uploads the model from the specified file.
   */
  virtual void uploadModel(std::string file_path) = 0;

 protected:
  IParser* parser;
  ISettings* settings;
};


#endif  // SRC_MODEL_INCLUDE_INTERFACE_MODEL_H
