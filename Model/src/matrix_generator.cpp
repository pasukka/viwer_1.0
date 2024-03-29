#include "matrix_generator.h"

Matrix4x4 MatrixGenerator::generate_scale_matrix(float xScale,
                                                           float yScale,
                                                           float zScale) {
  Matrix4x4 result;
  result(0, 0) = xScale;
  result(1, 1) = yScale;
  result(2, 2) = zScale;
  result(3, 3) = 1.0f;

  return result;
}

Matrix4x4 MatrixGenerator::generate_Xaxis_rotation_matrix(
    float angle) {
  Matrix4x4 result;
  result(0, 0) = 1.0f;
  result(1, 1) = cosf(angle);
  result(1, 2) = -sinf(angle);
  result(2, 1) = sinf(angle);
  result(2, 2) = cosf(angle);
  result(3, 3) = 1.0f;

  return result;
}

Matrix4x4 MatrixGenerator::generate_Yaxis_rotation_matrix(
    float angle) {
  Matrix4x4 result;
  result(0, 0) = cosf(angle);
  result(0, 2) = sinf(angle);
  result(1, 1) = 1.0f;
  result(2, 0) = -sinf(angle);
  result(2, 2) = cosf(angle);
  result(3, 3) = 1.0f;

  return result;
}

Matrix4x4 MatrixGenerator::generate_Zaxis_rotation_matrix(
    float angle) {
  Matrix4x4 result;
  result(0, 0) = cosf(angle);
  result(0, 1) = -sinf(angle);
  result(1, 0) = sinf(angle);
  result(1, 1) = cosf(angle);
  result(2, 2) = 1.0f;
  result(3, 3) = 1.0f;

  return result;
}

Matrix4x4 MatrixGenerator::generate_XYZaxis_rotation_matrix(
    float angleX, float angleY, float angleZ) {
  Matrix4x4 matrix = generate_Xaxis_rotation_matrix(angleX);
  matrix = matrix_mult_4x4(matrix, generate_Yaxis_rotation_matrix(angleY));
  matrix = matrix_mult_4x4(matrix, generate_Zaxis_rotation_matrix(angleZ));
  return matrix;
}

Matrix4x4 MatrixGenerator::matrix_mult_4x4(Matrix4x4 first,
                                                     Matrix4x4 second) {
  Matrix4x4 result;
  mult(4, 4, 4, &first(0, 0), &second(0, 0), &result(0, 0));
  return result;
}

void MatrixGenerator::mult(int M, int N, int K, const float* A,
                                const float* B, float* C) {
  for (int i = 0; i < M; ++i) {
    float* c = C + i * N;
    for (int j = 0; j < N; ++j) c[j] = 0;
    for (int k = 0; k < K; ++k) {
      const float* b = B + k * N;
      float a = A[i * K + k];
      for (int j = 0; j < N; ++j) c[j] += a * b[j];
    }
  }
}

Matrix4x4 MatrixGenerator::generate_translation_matrix(Vector3 vec) {
  Matrix4x4 result;
  result(0, 0) = 1.0f;
  result(0, 3) = vec(0);
  result(1, 1) = 1.0f;
  result(1, 3) = vec(1);
  result(2, 2) = 1.0f;
  result(2, 3) = vec(2);
  result(3, 3) = 1.0f;

  return result;
}

// opengl frustrum copy
Matrix4x4 MatrixGenerator::generate_frustrum_matrix(
    double left, double right, double bottom, double top, double nearVal,
    double farVal) {
  float A = (right + left) / (right - left);
  float B = (top + bottom) / (top - bottom);
  float C = -(farVal + nearVal) / (farVal - nearVal);
  float D = -2 * farVal * nearVal / (farVal - nearVal);
  float E = 2 * nearVal / (right - left);
  float F = 2 * nearVal / (top - bottom);

  Matrix4x4 result;
  result(0, 0) = E;
  result(0, 2) = A;
  result(1, 1) = F;
  result(1, 2) = B;
  result(2, 2) = C;
  result(2, 3) = D;
  result(3, 2) = -1;
  result(3, 3) = 1.0f;

  return result;
}

Matrix4x4 MatrixGenerator::generate_identity() {
  Matrix4x4 result;
  result(0, 0) = 1.0f;
  result(1, 1) = 1.0f;
  result(2, 2) = 1.0f;
  result(3, 3) = 1.0f;

  return result;
}
