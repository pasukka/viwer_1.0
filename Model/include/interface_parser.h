#if !defined(SRC_MODEL_INCLUDE_INTERFACE_PARSER_H)
#define SRC_MODEL_INCLUDE_INTERFACE_PARSER_H

/**
 * @file interface_parser.h
 * @author SevenStreams
 * @brief This file handles interface of parser
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#define MAX_NUM 1000
#define SEP ' '
#define START_CAPACITY 4

/**
 * @brief List of error types
 *
 */
enum { OK, ERROR, ERROR_FILE, ERROR_V, ERROR_F, EMPTY_FILE };

/**
 * @brief List of character constants
 *
 */
enum { VECTOR = 'v', FACE = 'f', SPACE = ' ' };

class Model;

/**
 * @brief The IParser class is an interface for parsing files.
 */
class IParser {
 public:
  /**
   * @brief Destructor for the IParser interface.
   */
  virtual ~IParser() {}

  /**
   * @brief Pure virtual function to parse a file.
   */
  virtual void parseFile() = 0;

  /**
   * @brief Pure virtual function to initialize the parser with a model.
   *
   * @param model The model to initialize the parser with.
   */
  virtual void initParser(Model *model) = 0;

 protected:
  Model *model;
};

#include "model.h"

#endif  // SRC_MODEL_INCLUDE_INTERFACE_PARSER_H
