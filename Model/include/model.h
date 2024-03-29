#if !defined(SRC_MODEL_INCLUDE_MODEL_H)
#define SRC_MODEL_INCLUDE_MODEL_H

/**
 * @file model.h
 * @author SevenStreams
 * @brief This file handles working with model
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "interface_model.h"
#include "matrix_generator.h"

class Model : public IModel {
 public:
  /**
   * @brief The functions handles freeing model
   *
   */
  void deleteModel();

  /**
   * @brief The functions handles initializing model
   *
   */
  void initModel();

  /**
   * @brief The functions handles uploading model
   *
   */
  void uploadModel(std::string file_path);

  /**
   * Constructs a Model object with the given parser and settings.
   *
   * @param p a pointer to an IParser object
   * @param s a pointer to an ISettings object
   *
   * @throws ErrorType description of error
   */
  Model(IParser* p);

  /**
   * @brief Destructor for the Model class.
   *
   * This destructor calls the deleteModel() function to perform cleanup tasks.
   */
  ~Model() { deleteModel(); }

  /**
   * @brief The functions handles freeing model
   *
   */
  size_t getVerticesCount();

  /**
   * @brief The functions handles initializing model
   *
   * @param count description of parameter
   *
   */
  void setVerticesCount(size_t count);

  /**
   * @brief The functions handles getting the indices count
   *
   */
  size_t getIndicesCount();

  /**
   * @brief The functions handles setting the indices count
   *
   * @param count description of parameter
   *
   */
  void setIndicesCount(size_t count);

  /**
   * @brief The functions sets the file path
   *
   * @param path description of parameter
   *
   */
  void setFilePath(std::string path);

  /**
   * @brief The function gets the file path
   *
   * @return description of return value
   *
   */
  const std::string& getFilePath() const;

  /**
   * @brief The function sets the error code
   *
   * @param error description of parameter
   *
   */
  void setErrorCode(int error);

  /**
   * @brief The function gets the error code
   *
   * @return description of return value
   *
   */
  int getErrorCode();

  /**
   * @brief The function gets the 3D vertices
   *
   * @return description of return value
   *
   */
  Vector3* getVertices3d();

  /**
   * @brief The function sets the 3D vertices
   *
   * @param vertices description of parameter
   *
   */
  void setVertices3d(Vector3* vertices);

  /**
   * @brief The function gets the 4D vertices
   *
   * @return description of return value
   *
   */
  Vector4* getVertices4d();

  /**
   * @brief The function sets the 4D vertices
   *
   * @param vertices description of parameter
   *
   */
  void setVertices4d(Vector4* vertices);

  /**
   * @brief The function gets the indices
   *
   * @return description of return value
   *
   */
  unsigned int* getIndices();

  /**
   * @brief The function sets the indices
   *
   * @param indices description of parameter
   *
   */
  void setIndices(unsigned int* indices);

 private:
  IParser* parser;
  std::string file_path;
  Vector3* vertices3d;
  Vector4* vertices4d;
  size_t vertices_count;  // size of vertices3d array
  unsigned int* indices;
  size_t indices_count;  // indices_count * 3 == size of indices array
  int error_code;        // if 0 -- there is no errors yet

  /**
   * @brief The functions handles normalizing model
   *
   */
  void normalizeModel();

  /**
   * @brief The functions handles creating 4d vertices
   *
   */
  void generate4dFrom3d();
  /**
   * @brief Make the 4d vector from 3d vector
   *
   * @param vector 3d vector
   * @return Vector4 4d vector
   */
  Vector4 get4dBy3d(Vector3 vector);
};


#endif  // SRC_MODEL_INCLUDE_MODEL_H
