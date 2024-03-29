#include "matrix.h"

float& Vector3::x() { return xVal; }
float& Vector3::y() { return yVal; }
float& Vector3::z() { return zVal; }

float& Vector3::r() { return rVal; }
float& Vector3::g() { return gVal; }
float& Vector3::b() { return bVal; }

float& Vector3::operator()(int col) {
  float* result = nullptr;
  switch (col) {
    case 0:
      result = &xVal;
      break;
    case 1:
      result = &yVal;
      break;
    case 2:
      result = &zVal;
      break;
    default:
      throw std::out_of_range("Vector3 index out of range");
  }
  return *result;
}

const float& Vector3::operator()(int col) const {
  const float* result = nullptr;
  switch (col) {
    case 0:
      result = &xVal;
      break;
    case 1:
      result = &yVal;
      break;
    case 2:
      result = &zVal;
      break;
    default:
      throw std::out_of_range("Vector3 index out of range");
  }
  return *result;
}

float& Vector4::x() { return xVal; }
float& Vector4::y() { return yVal; }
float& Vector4::z() { return zVal; }
float& Vector4::w() { return wVal; }

float& Vector4::r() { return rVal; }
float& Vector4::g() { return gVal; }
float& Vector4::b() { return bVal; }

const float& Vector4::x() const { return xVal; }
const float& Vector4::y() const { return yVal; }
const float& Vector4::z() const { return zVal; }
const float& Vector4::w() const { return wVal; }

const float& Vector4::r() const { return rVal; }
const float& Vector4::g() const { return gVal; }
const float& Vector4::b() const { return bVal; }

float& Vector4::operator()(int col) {
  float* result = nullptr;
  switch (col) {
    case 0:
      result = &xVal;
      break;
    case 1:
      result = &yVal;
      break;
    case 2:
      result = &zVal;
      break;
    case 3:
      result = &wVal;
      break;
    default:
      throw std::out_of_range("Vector4 index out of range");
  }
  return *result;
}

const float& Vector4::operator()(int col) const {
  const float* result = nullptr;
  switch (col) {
    case 0:
      result = &xVal;
      break;
    case 1:
      result = &yVal;
      break;
    case 2:
      result = &zVal;
      break;
    case 3:
      result = &wVal;
      break;
    default:
      throw std::out_of_range("Vector4 index out of range");
  }
  return *result;
}

Matrix4x4::Matrix4x4() : row1(), row2(), row3(), row4() {}

float& Matrix4x4::operator()(int row, int col) {
  float* result = nullptr;
  switch (row) {
    case 0:
      result = &row1(col);
      break;
    case 1:
      result = &row2(col);
      break;
    case 2:
      result = &row3(col);
      break;
    case 3:
      result = &row4(col);
      break;
    default:
      throw std::out_of_range("Matrix4x4 row index out of range");
  }
  return *result;
}

const float& Matrix4x4::operator()(int row, int col) const {
  const float* result = nullptr;
  switch (row) {
    case 0:
      result = &row1(col);
      break;
    case 1:
      result = &row2(col);
      break;
    case 2:
      result = &row3(col);
      break;
    case 3:
      result = &row4(col);
      break;
    default:
      throw std::out_of_range("Matrix4x4 row index out of range");
  }
  return *result;
}

const Vector4* Matrix4x4::toArray() const { return &row1; }
