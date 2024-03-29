#if !defined(SRC_MODEL_INCLUDE_MATRIX_H)
#define SRC_MODEL_INCLUDE_MATRIX_H

/**
 * @file matrix.h
 * @author SevenStreams
 * @brief This file handles working with matrix
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <stdexcept>
/**
 * @brief 3D Vector
 *
 */
class Vector3 {
 public:
  /**
   * @brief Default constructor
   */
  Vector3() : xVal(0.0f), yVal(0.0f), zVal(0.0f){};

  /**
   * @brief Constructor initializing all components
   *
   * @param x X component
   * @param y Y component
   * @param z Z component
   */
  Vector3(float x, float y, float z) : xVal(x), yVal(y), zVal(z){};

  /**
   * @brief Get the x component of the vector.
   * @return Reference to the x component.
   */
  float& x();

  /**
   * @brief Get the y component of the vector.
   * @return Reference to the y component.
   */
  float& y();
  /**
   * @brief Get the z component of the vector.
   * @return Reference to the z component.
   */
  float& z();

  /**
   * @brief Get the r component of the vector.
   * @return Reference to the r component.
   */
  float& r();

  /**
   * @brief Get the g component of the vector.
   * @return Reference to the g component.
   */
  float& g();

  /**
   * @brief Get the b component of the vector.
   * @return Reference to the b component.
   */
  float& b();

  /**
   * @brief Access element at column col
   *
   * @param col Column index
   * @return Reference to the element at column col
   */
  float& operator()(int col);

  /**
   * @brief Access element at column col (const version)
   *
   * @param col Column index
   * @return Const reference to the element at column col
   */
  const float& operator()(int col) const;

 private:
  union {
    float xVal, rVal;
  };
  union {
    float yVal, gVal;
  };
  union {
    float zVal, bVal;
  };
};

/**
 * @brief 4D Vector
 *
 */
class Vector4 {
 public:
  /**
   * @brief Default constructor
   */
  Vector4() : xVal(0.0f), yVal(0.0f), zVal(0.0f), wVal(0.0f){};

  /**
   * @brief Constructor initializing all components
   *
   * @param x X component
   * @param y Y component
   * @param z Z component
   * @param w W component
   */
  Vector4(float x, float y, float z, float w)
      : xVal(x), yVal(y), zVal(z), wVal(w){};

  /**
   * @brief Get the x component of the vector.
   * @return Reference to the x component.
   */
  float& x();

  /**
   * @brief Get the y component of the vector.
   * @return Reference to the y component.
   */
  float& y();
  /**
   * @brief Get the z component of the vector.
   * @return Reference to the z component.
   */
  float& z();

  /**
   * @brief Get the w component of the vector.
   * @return Reference to the w component.
   */
  float& w();

  /**
   * @brief Get the r component of the vector.
   * @return Reference to the r component.
   */
  float& r();

  /**
   * @brief Get the g component of the vector.
   * @return Reference to the g component.
   */
  float& g();

  /**
   * @brief Get the b component of the vector.
   * @return Reference to the b component.
   */
  float& b();

  /**
   * @brief Get the x component of the vector.
   * @return Reference to the x component.
   */
  const float& x() const;

  /**
   * @brief Get the y component of the vector.
   * @return Reference to the y component.
   */
  const float& y() const;
  /**
   * @brief Get the z component of the vector.
   * @return Reference to the z component.
   */
  const float& z() const;

  /**
   * @brief Get the w component of the vector.
   * @return Reference to the w component.
   */
  const float& w() const;

  /**
   * @brief Get the r component of the vector.
   * @return Reference to the r component.
   */
  const float& r() const;

  /**
   * @brief Get the g component of the vector.
   * @return Reference to the g component.
   */
  const float& g() const;

  /**
   * @brief Get the b component of the vector.
   * @return Reference to the b component.
   */
  const float& b() const;

  /**
   * @brief Access element at column col
   *
   * @param col Column index
   * @return Reference to the element at column col
   */
  float& operator()(int col);

  /**
   * @brief Access element at column col (const version)
   *
   * @param col Column index
   * @return Const reference to the element at column col
   */
  const float& operator()(int col) const;

 private:
  union {
    float xVal, rVal;
  };
  union {
    float yVal, gVal;
  };
  union {
    float zVal, bVal;
  };
  float wVal;
};

/**
 * @brief Matrix 4x4
 *
 */
class Matrix4x4 {
 public:
  /**
   * @brief Default constructor
   */
  Matrix4x4();

  /**
   * @brief Access element at (row, col)
   *
   * @param row Row index
   * @param col Column index
   * @return Reference to the element at (row, col)
   */
  float& operator()(int row, int col);

  /**
   * @brief Access element at (row, col) (const version)
   *
   * @param row Row index
   * @param col Column index
   * @return Const reference to the element at (row, col)
   */
  const float& operator()(int row, int col) const;

  /**
   * @brief Returns a pointer to the first element of the 4x4 matrix as a
   * Vector4 array.
   *
   * @return A pointer to the first element of the matrix as a Vector4 array.
   */
  const Vector4* toArray() const;

 private:
  Vector4 row1;
  Vector4 row2;
  Vector4 row3;
  Vector4 row4;
};

#endif  // SRC_MODEL_INCLUDE_MATRIX_H
