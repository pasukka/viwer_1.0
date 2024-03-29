#if !defined(SRC_MODEL_INCLUDE_PARSER_H)
#define SRC_MODEL_INCLUDE_PARSER_H

/**
 * @file parser.h
 * @author SevenStreams
 * @brief This file handles parsing of .obj files
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <string>
#include <vector>

#include "interface_parser.h"

class Model;

class Parser : public IParser {
  using Vector = std::vector<double>;

 public:
  Parser() : model(NULL) {}

  /**
   * @brief The function handles checking model before parsing
   *
   */
  void parseFile() override;

  /**
   * @brief Initializes the parser with a model.
   *
   * This function sets the `model` member variable of the `Parser` class to the
   * provided `Model` object.
   *
   * @param m A pointer to the `Model` object to be used for parsing.
   */
  void initParser(Model *m) override;

 private:
  Model *model;
  Vector vertexes;
  Vector vertex_indexes;

  /**
   * @brief Clears the vectors containing vertex data and vertex indexes.
   */
  void clearVectors();

  /**
   * @brief This function checks whether file exists or not
   *
   * @param filename File's name
   * @return int An error
   */
  int fileExists(const std::string &filename);

  /**
   * @brief This function checks whether file if empty or not
   *
   * @param filename File's name
   * @return int An error
   */
  int fileEmpty(const std::string &filename);

  /**
   * @brief The function handles parsing model
   *
   */
  void process();

  /**
   * @brief This function handles adding list of vertexes to model
   *
   */
  void vertexesToModel();

  /**
   * @brief This function handles adding list of indexes to model
   *
   * @param vertex_indexes A list of vertexes' indexes
   */
  void indexesToModel();

  /**
   * @brief This function handles extracting numbers and adding them to the list
   * of vertexes
   *
   * @param str An input string from file
   * @return int An error
   */
  int addToVector(const std::string &str);

  /**
   * @brief This function handles extracting numbers and adding them to the list
   * of indexes
   *
   * @param str An input string from file
   * @return int An error
   */
  int parseFace(const std::string &str);
};

#include "model.h"

#endif  // SRC_MODEL_INCLUDE_PARSER_H
