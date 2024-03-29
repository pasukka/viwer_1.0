#ifndef SRC_VIEW_INCLUDE_VIEWER_WIDGET_H
#define SRC_VIEW_INCLUDE_VIEWER_WIDGET_H
#define GL_SILENCE_DEPRECATION

/**
 * @file viewer_widget.h
 * @author SevenStreams
 * @brief This file handles working with viewer widget
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QMouseEvent>
#include <QVector3D>
#include <QWheelEvent>
#include <QtGlobal>

#include "controller.h"
#include "strategies.h"
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
#include <QOpenGLFunctions_3_3_Compatibility>
#include <QOpenGLWidget>
#else
#include <QOpenGLFunctions>
#include <QtOpenGLWidgets/QOpenGLWidget>
#endif
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

/**
 * @brief The viewer widget class
 */
class viewer_widget : public QOpenGLWidget,
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
                      protected QOpenGLFunctions_3_3_Compatibility
#else
                      protected QOpenGLFunctions
#endif
{
  Q_OBJECT

 public:
  /**
   * @brief The function handles initializing viewer widget
   *
   * @return viewer_widget
   */
  viewer_widget(QWidget *parent = nullptr);

  /**
   * @brief The function handles destroying viewer widget
   *
   */
  ~viewer_widget();

  /**
   * @brief Vertex buffer object
   *
   */
  GLuint VBO;

  /**
   * @brief Edges buffer object
   *
   */
  GLuint EBO;

  /**
   * @brief The function sets controller
   *
   * @param c The controller
   */
  void setDependencies(Controller *c);

  /**
   * @brief The function changes model
   *
   */
  void changeModel();

 signals:
  void changeRotationAngles();
  void changeScaling();
  void changeTranslation();

 private slots:
  /**
   * @brief The function rotates model by x
   *
   * @param value The value
   */
  void RotationXChangeOutside(int value);

  /**
   * @brief The function rotates model by y
   *
   * @param value The value
   */
  void RotationYChangeOutside(int value);

  /**
   * @brief The function rotates model by z
   *
   * @param value The value
   */
  void RotationZChangeOutside(int value);

  /**
   * @brief The function scales model
   *
   * @param value The value
   */
  void ScalingChangeOutside(int value);

  /**
   * @brief The function translates model by x
   *
   * @param value The value
   */
  void TranslationXChangeOutside(float value);

  /**
   * @brief The function translates model by y
   *
   * @param value The value
   */
  void TranslationYChangeOutside(float value);

  /**
   * @brief The function translates model by z
   *
   * @param value The value
   */
  void TranslationZChangeOutside(float value);

  /**
   * @brief The function updates settings
   *
   */
  void updateSettings();

 protected:
  /**
   * @brief The function initializes GL buffers
   *
   */
  void initializeGL();

  /**
   * @brief The function paints model
   *
   */
  void paintGL();

  /**
   * @brief The function handles wheeling model
   *
   * @param event The event
   */
  void wheelEvent(QWheelEvent *event);

  /**
   * @brief The function handles pressing mouse
   *
   * @param event The event
   */
  void mousePressEvent(QMouseEvent *event);

  /**
   * @brief The function handles mouse moving
   *
   * @param event The event
   */
  void mouseMoveEvent(QMouseEvent *event);

  /**
   * @brief The function handles releasing mouse
   *
   * @param event The event
   */
  void mouseReleaseEvent(QMouseEvent *event);

  /**
   * @brief The function handles key pressing
   *
   * @param event The event
   */
  void keyPressEvent(QKeyEvent *event);

  /**
   * @brief The function updates buffers
   *
   */
  void updateVertexBuffer();

  /**
   * @brief The function enables settings
   *
   */
  void enableSettings();

  /**
   * @brief The function resets state
   *
   */
  void ResetState();

 private:
  Controller *controller;
  ContextStrategy context;
  bool dragging = false;
  int last_x, last_y;
};

#endif  // SRC_VIEW_INCLUDE_VIEWER_WIDGET_H
