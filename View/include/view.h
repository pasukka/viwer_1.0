#ifndef SRC_VIEW_INCLUDE_VIEW_H
#define SRC_VIEW_INCLUDE_VIEW_H
#define HALF_SCALE_SLIDER 50.0f

/**
 * @file view.h
 * @author SevenStreams
 * @brief This file handles working with view
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QMovie>

#include "controller.h"
#include "qgifimage.h"
#include "settings_path.h"
#include "settings_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class View;
}
QT_END_NAMESPACE

/**
 * @brief The view class
 */
class View : public QMainWindow {
  Q_OBJECT

 public:
  /**
   * @brief The function handles initializing view
   *
   * @param c The controller
   * @param parent The parent widget
   * @return View
   */
  View(Controller *c, QWidget *parent = nullptr);

  /**
   * @brief The function handles destroying view
   *
   */
  ~View();

  /**
   * @brief The function handles starting event loop for view
   *
   */
  void startEventLoop();

 private slots:
  /**
   * @brief The function handles opening settings
   *
   */
  void SettingsClicked();

  /**
   * @brief The function handles opening file
   *
   */
  void FileOpenClicked();

  /**
   * @brief The function saving image
   *
   */
  void SaveAsImageClicked();

  /**
   * @brief The function saving gif
   *
   */
  void SaveAsGifClicked();

  /**
   * @brief The function handles timer for gif
   *
   * @param event The timer event
   */
  void timerEvent(QTimerEvent *event) override;

  /**
   * @brief The function rotates model
   *
   */
  void RotationsAnglesChanged();

  /**
   * @brief The function scales model
   *
   */
  void ScalingChanged();

  /**
   * @brief The function translate model
   *
   */
  void TranslationChanged();

  /**
   * @brief The function handles x translation slider
   *
   * @param value The value
   */
  void translationSliderXHandler(int value);

  /**
   * @brief The function handles y translation slider
   *
   * @param value The value
   */
  void translationSliderYHandler(int value);

  /**
   * @brief The function handles z translation slider
   *
   * @param value The value
   */
  void translationSliderZHandler(int value);

  /**
   * @brief The function resets values
   *
   */
  void ResetAllValues();

 signals:
  void translationSliderXChanged(float value);
  void translationSliderYChanged(float value);
  void translationSliderZChanged(float value);

 private:
  Controller *controller;
  Ui::View *ui;
  Settings_widget *settings_widget;
  QGifImage *gif_;
  int gif_iterator_;

 protected:
  /**
   * @brief The function handles closing settings
   *
   * @param event The event
   */
  void closeEvent(QCloseEvent *event) override;

  /**
   * @brief The function handles messaging error
   *
   * @param error Error string
   */
  void ErrorMessage(Controller::string error);

  /**
   * @brief The function sets number of vertices
   *
   * @param number The number
   */
  void setVerticesNum(int number);

  /**
   * @brief The function sets number of edges
   *
   * @param number The number
   */
  void setEdgesNum(int number);
};

#endif  // SRC_VIEW_INCLUDE_VIEW_H
