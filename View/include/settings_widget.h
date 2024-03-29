#ifndef SRC_VIEW_INCLUDE_SETTINGS_WIDGET_H
#define SRC_VIEW_INCLUDE_SETTINGS_WIDGET_H

/**
 * @file settings_widget.h
 * @author SevenStreams
 * @brief This file handles working with settings widget
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QColorDialog>
#include <QFrame>
#include <QWidget>

#include "commands.h"
#include "settings_path.h"
#include "viewer_widget.h"

namespace Ui {
class Settings_widget;
}

/**
 * @brief The settings widget class
 */
class Settings_widget : public QWidget {
  Q_OBJECT

 public:
  /**
   * @brief The function handles initializing settings widget
   *
   * @param parent The parent widget
   * @return Settings widget
   */
  explicit Settings_widget(QWidget *parent = nullptr);

  /**
   * @brief The function handles initializing settings widget with view widget
   * and controller
   *
   * @param view_field The view widget
   * @param c The controller
   * @return Settings widget
   */
  explicit Settings_widget(viewer_widget *view_field, Controller *c);

  /**
   * @brief The function handles destroying settings widget
   *
   */
  ~Settings_widget();

 private slots:
  /**
   * @brief The function handles changing projection type
   *
   * @param index Projection type index
   */
  void ProjectionTypeChanged(int index);

  /**
   * @brief The function handles changing edges type
   *
   * @param index Edges type index
   */
  void EdgesTypeChanged(int index);

  /**
   * @brief The function handles changing display type
   *
   * @param index Display type index
   */
  void DisplayTypeChanged(int index);

  /**
   * @brief The function handles changing background color
   *
   */
  void BackgroundColorButtonClicked();

  /**
   * @brief The function handles changing edges color
   *
   */
  void EdgesColorButtonClicked();

  /**
   * @brief The function handles changing vertices color
   *
   */
  void VerticesColorButtonClicked();

  /**
   * @brief The function handles changing vertices size
   *
   * @param value Vertices size value
   */
  void VerticesSizeChanged(double value);

  /**
   * @brief The function handles changing edges thickness
   *
   * @param value Edges thickness value
   */
  void EdgesThicknessChanged(double value);

 signals:
  void SettingsChanged();

 private:
  /**
   * @brief The function handles changing frame color
   *
   * @param frame The frame
   * @param red The number for red
   * @param green The number for green
   * @param blue The number for blue
   */
  void ChangeFrameColor(QFrame *frame, int red, int green, int blue);

  /**
   * @brief The function initialize settings
   *
   */
  void InitializeElements();

  Ui::Settings_widget *ui;
  viewer_widget *view_field_;
  Controller *controller_;
  CommandManager *commandManager;
};

#endif  // SRC_VIEW_INCLUDE_SETTINGS_WIDGET_H
