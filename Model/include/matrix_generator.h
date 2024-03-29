#if !defined(SRC_MODEL_INCLUDE_MATRIX_GENERATOR_H)
#define SRC_MODEL_INCLUDE_MATRIX_GENERATOR_H

/**
 * @file matrix_generator.h
 * @author SevenStreams
 * @brief This file handles transforming matrix
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <cmath>

#include "matrix.h"

#define MINIMIZE_FACTOR 0.95f;

class MatrixGenerator {
 public:
  /**
   * @brief The function generates scale matrix
   *
   * @param xScale The x scale
   * @param yScale The y scale
   * @param zScale The z scale
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_scale_matrix(float xScale, float yScale,
                                         float zScale);

  /**
   * @brief The function rotates matrix by x
   *
   * @param angle x angle for rotation
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_Xaxis_rotation_matrix(float angle);

  /**
   * @brief The function rotates matrix by y
   *
   * @param angle y angle for rotation
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_Yaxis_rotation_matrix(float angle);

  /**
   * @brief The function rotates matrix by z
   *
   * @param angle z angle for rotation
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_Zaxis_rotation_matrix(float angle);

  /**
   * @brief The function rotates matrix
   *
   * @param angleX x angle for rotation
   * @param angleY y angle for rotation
   * @param angleZ z angle for rotation
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_XYZaxis_rotation_matrix(float angleX, float angleY,
                                                    float angleZ);

  /**
   * @brief The function translates matrix
   *
   * @param vec 3d vector
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_translation_matrix(Vector3 vec);

  /**
   * @brief The function generates frustrum matrix
   *
   * @param left left number
   * @param right right number
   * @param bottom bottom number
   * @param top top number
   * @param nearVal near value number
   * @param farVal far value number
   * @return Matrix4x4 Result matrix 4x4
   */
  static Matrix4x4 generate_frustrum_matrix(double left, double right,
                                            double bottom, double top,
                                            double nearVal, double farVal);

  /**
   * @brief The function generates matrix
   *
   * @return Matrix4x4
   */
  static Matrix4x4 generate_identity();

  /**
   * @brief The function handles multiplication of 2 matrixes 4x4
   *
   * @param first First matrix 4x4
   * @param second Second matrix 4x4
   * @return v_matrix4x4 The result of matrix multiplication
   */
  static Matrix4x4 matrix_mult_4x4(Matrix4x4 first, Matrix4x4 second);

  /**
   * @brief The function handles matrix multiplication
   *
   * @param M Number of rows
   * @param N Number of columns
   * @param K Number of rows
   * @param A First matrix
   * @param B Second matrix
   * @param C The result of multiplication
   */
  static void mult(int M, int N, int K, const float* A, const float* B,
                   float* C);

  /**
   * @brief The function apply transformation matrix to the vector
   *
   * @param start_vertex
   * @param transf_matrix
   * @return Vector4 The result vector
   */
  static inline Vector4 single_f4d_vertex_processing(Vector4 start_vertex,
                                                     Matrix4x4 transf_matrix) {
    Vector4 result;
    MatrixGenerator().mult(4, 1, 4, &(transf_matrix(0, 0)), &(start_vertex.x()),
                           &(result.x()));
    result.x() = result.x() / result.w();
    result.y() = result.y() / result.w();
    result.z() = result.z() / result.w();
    result.w() = 1;
    return result;
  }

  /**
   * @brief The function apply transformation matrix to all vectors in the list
   *
   * @param in_array Input 4d vector
   * @param out_array Output 4d vector
   * @param count Number of vectors
   * @param transf_matrix Matrix 4x4
   */
  static inline void f4d_vertex_array_processing(Vector4* in_array,
                                                 Vector4* out_array, int count,
                                                 Matrix4x4 transf_matrix) {
    for (int i = 0; i < count; ++i) {
      out_array[i] = single_f4d_vertex_processing(in_array[i], transf_matrix);
    }
  }
};

#endif  // SRC_MODEL_INCLUDE_MATRIX_GENERATOR_H
