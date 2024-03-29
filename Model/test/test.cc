#include <gtest/gtest.h>

#include "matrix_generator.h"
#include "model.h"
#include "parser.h"
#include "settings.h"
#include "settings_path.h"

#define EPSILON 1e-6

TEST(ModelTest, Error1) {
  std::string path = OBJECTS_PATH;
  path += "/test_ERROR.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);
  int error = model.getErrorCode();
  EXPECT_EQ(error, ERROR);
}

TEST(ModelTest, Error2) {
  std::string path = OBJECTS_PATH;
  path += "/test_ERROR_FILE.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);
  int error = model.getErrorCode();
  EXPECT_EQ(error, ERROR_FILE);
}

TEST(ModelTest, Error3) {
  std::string path = OBJECTS_PATH;
  path += "/test_ERROR_V.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);
  int error = model.getErrorCode();
  EXPECT_EQ(error, ERROR_V);
}

TEST(ModelTest, Error4) {
  std::string path = OBJECTS_PATH;
  path += "/test_EMPTY_FILE.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);
  int error = model.getErrorCode();
  EXPECT_EQ(error, EMPTY_FILE);
}

TEST(ParserTest, TestParce1) {
  std::string path = OBJECTS_PATH;
  path += "/test.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);

  EXPECT_EQ(model.getErrorCode(), OK);

  double real_result_vert[100] = {0, 0,      0, 1,   0,    0,
                                  0, 100e-5, 0, 0.5, -0.5, 1.6};
  unsigned int real_result_ind[100] = {0, 1, 2, 3, 0, 2, 3, 1, 0, 3, 0, 0,
                                       2, 1, 2, 2, 2, 3, 2, 3, 0, 2, 0, 3,
                                       2, 3, 0, 3, 1, 0, 3, 0, 3, 2, 1, 2};

  int j = 0;
  for (size_t i = 0; i < model.getVerticesCount(); ++i) {
    EXPECT_NEAR(real_result_vert[j++], model.getVertices3d()[i].x(), EPSILON);
    EXPECT_NEAR(real_result_vert[j++], model.getVertices3d()[i].y(), EPSILON);
    EXPECT_NEAR(real_result_vert[j++], model.getVertices3d()[i].z(), EPSILON);
  }

  for (size_t i = 0; i < model.getIndicesCount(); ++i) {
    EXPECT_EQ(real_result_ind[i], model.getIndices()[i]);
  }
}

TEST(ParserTest, TestParce2) {
  std::string path = OBJECTS_PATH;
  path += "/test_triangle.obj";
  Parser parser;
  Model model(&parser);
  model.uploadModel(path);
  model.initModel();
  Vector4 real_result[] = {{0.475f, -0.475f, -0.475f, 1.0f},
                                {-0.475f, 0.475f, -0.475f, 1.0f},
                                {-0.475f, -0.475f, 0.475f, 1.0f}};

  int error = model.getErrorCode();
  EXPECT_EQ(error, OK);
  for (int i = 0; i < 3; ++i) {
    EXPECT_NEAR(model.getVertices4d()[i].x(), real_result[i].x(), EPSILON);
    EXPECT_NEAR(model.getVertices4d()[i].y(), real_result[i].y(), EPSILON);
    EXPECT_NEAR(model.getVertices4d()[i].z(), real_result[i].z(), EPSILON);
    EXPECT_NEAR(model.getVertices4d()[i].w(), real_result[i].w(), EPSILON);
  }
}

TEST(ParserTest, TestParce3) {
  Vector4 a[] = {{1.0f, 0.0f, 0.0f, 1.0f},
                      {0.0f, 1.0f, 0.0f, 1.0f},
                      {0.0f, 0.0f, 1.0f, 1.0f}};
  Matrix4x4 rotation =
      MatrixGenerator().generate_XYZaxis_rotation_matrix(M_PI, 0.0f, 0.0f);
  Vector4 b[3];
  MatrixGenerator().f4d_vertex_array_processing(a, b, 3, rotation);
  Vector4 real_result[] = {{1.0f, 0.0f, 0.0f, 1.0f},
                                {0.0f, -1.0f, 0.0f, 1.0f},
                                {0.0f, 0.0f, -1.0f, 1.0f}};
  for (int i = 0; i < 3; ++i) {
    EXPECT_NEAR(b[i].x(), real_result[i].x(), EPSILON);
    EXPECT_NEAR(b[i].y(), real_result[i].y(), EPSILON);
    EXPECT_NEAR(b[i].z(), real_result[i].z(), EPSILON);
    EXPECT_NEAR(b[i].w(), real_result[i].w(), EPSILON);
  }
}

TEST(ParserTest, TestParce4) {
  Vector4 a[] = {{1.0f, 0.0f, 0.0f, 1.0f},
                      {0.0f, 1.0f, 0.0f, 1.0f},
                      {0.0f, 0.0f, 1.0f, 1.0f}};
  Matrix4x4 scale_matrix =
      MatrixGenerator().generate_scale_matrix(0.5f, 0.5f, 0.5f);
  Vector4 b[3];
  MatrixGenerator().f4d_vertex_array_processing(a, b, 3, scale_matrix);
  Vector4 real_result[] = {{0.5f, 0.0f, 0.0f, 1.0f},
                                {0.0f, 0.5f, 0.0f, 1.0f},
                                {0.0f, 0.0f, 0.5f, 1.0f}};
  for (int i = 0; i < 3; ++i) {
    EXPECT_NEAR(b[i].x(), real_result[i].x(), EPSILON);
    EXPECT_NEAR(b[i].y(), real_result[i].y(), EPSILON);
    EXPECT_NEAR(b[i].z(), real_result[i].z(), EPSILON);
    EXPECT_NEAR(b[i].w(), real_result[i].w(), EPSILON);
  }
}

TEST(ParserTest, TestParce5) {
  Vector4 a[] = {{1.0f, 0.0f, 0.0f, 1.0f},
                      {0.0f, 1.0f, 0.0f, 1.0f},
                      {0.0f, 0.0f, 1.0f, 1.0f}};
  Vector3 x_right = {0.5f, 0.0f, 0.0f};
  Matrix4x4 translation_matrix =
      MatrixGenerator().generate_translation_matrix(x_right);
  Vector4 b[3];
  MatrixGenerator().f4d_vertex_array_processing(a, b, 3,
                                                     translation_matrix);
  Vector4 real_result[] = {{1.5f, 0.0f, 0.0f, 1.0f},
                                {0.5f, 1.0f, 0.0f, 1.0f},
                                {0.5f, 0.0f, 1.0f, 1.0f}};
  for (int i = 0; i < 3; ++i) {
    EXPECT_NEAR(b[i].x(), real_result[i].x(), EPSILON);
    EXPECT_NEAR(b[i].y(), real_result[i].y(), EPSILON);
    EXPECT_NEAR(b[i].z(), real_result[i].z(), EPSILON);
    EXPECT_NEAR(b[i].w(), real_result[i].w(), EPSILON);
  }
}

TEST(ParserTest, TestParce6) {
  Matrix4x4 identity = MatrixGenerator().generate_identity();
  Vector4 real_result[] = {{1.0f, 0.0f, 0.0f, 0.0f},
                                {0.0f, 1.0f, 0.0f, 0.0f},
                                {0.0f, 0.0f, 1.0f, 0.0f},
                                {0.0f, 0.0f, 0.0f, 1.0f}};

  const Vector4* row_ptr = identity.toArray();

  for (int i = 0; i < 4; ++i) {
    const Vector4& row = *(row_ptr + i);
    EXPECT_NEAR(row.x(), real_result[i].x(), EPSILON);
    EXPECT_NEAR(row.y(), real_result[i].y(), EPSILON);
    EXPECT_NEAR(row.z(), real_result[i].z(), EPSILON);
    EXPECT_NEAR(row.w(), real_result[i].w(), EPSILON);
  }
}

TEST(ParserTest, TestParce7) {
  Vector4 a[] = {{1.0f, 0.0f, -1.5f, 1.0f},
                      {0.0f, 1.0f, -0.5f, 1.0f},
                      {0.0f, 0.0f, -1.0f, 1.0f}};
  Matrix4x4 frustrum_matrix =
      MatrixGenerator().generate_frustrum_matrix(-0.065, 0.065, -0.065,
                                                      0.065, 0.1, 2.0);
  ;
  Vector4 b[3];
  MatrixGenerator().f4d_vertex_array_processing(a, b, 3, frustrum_matrix);
  Vector4 real_result[] = {{0.615385f, 0.0f, 0.578947f, 1.0f},
                                {0.0f, 1.025641f, 0.228070f, 1.0f},
                                {0.0f, 0.0f, 0.447368f, 1.0f}};
  for (int i = 0; i < 3; ++i) {
    EXPECT_NEAR(b[i](0), real_result[i](0), EPSILON);
    EXPECT_NEAR(b[i](1), real_result[i](1), EPSILON);
    EXPECT_NEAR(b[i](2), real_result[i](2), EPSILON);
    EXPECT_NEAR(b[i](3), real_result[i](3), EPSILON);
  }
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
