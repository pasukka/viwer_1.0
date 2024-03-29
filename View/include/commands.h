#if !defined(SRC_MODEL_INCLUDE_COMMANDS_H)
#define SRC_MODEL_INCLUDE_COMMANDS_H

/**
 * @file commands.h
 * @author SevenStreams
 * @brief This file handles working with commend for changing settings
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <QColorDialog>

#include "command_manager.h"
#include "controller.h"

/**
 * @brief The class for projection type
 */
class ProjectionTypeChange : public Command {
 public:
  /**
   * @brief The function handles initializing projection type
   *
   * @param controller The controller
   * @param index The index of type
   * @return Projection Type
   */
  ProjectionTypeChange(Controller *controller, int index)
      : controller_(controller), index(index){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  int index;
};

/**
 * @brief The class for edges type
 */
class EdgesTypeChange : public Command {
 public:
  /**
   * @brief The function handles initializing edges type
   *
   * @param controller The controller
   * @param index The index of type
   * @return Edges type
   */
  EdgesTypeChange(Controller *controller, int index)
      : controller_(controller), index(index){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  int index;
};

/**
 * @brief The class for display type
 */
class DisplayTypeChange : public Command {
 public:
  /**
   * @brief The function handles initializing display type
   *
   * @param controller The controller
   * @param index The index of type
   * @return Display type
   */
  DisplayTypeChange(Controller *controller, int index)
      : controller_(controller), index(index){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  int index;
};

/**
 * @brief The class for vertices size
 */
class VerticesSizeChange : public Command {
 public:
  /**
   * @brief The function handles initializing vertices size
   *
   * @param controller The controller
   * @param value The value of size
   * @return Vertices size
   */
  VerticesSizeChange(Controller *controller, double value)
      : controller_(controller), value(value){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  double value;
};

/**
 * @brief The class for edges thickness
 */
class EdgesThicknessChange : public Command {
 public:
  /**
   * @brief The function handles initializing edges thickness
   *
   * @param controller The controller
   * @param value The value of thickness
   * @return Edges thickness
   */
  EdgesThicknessChange(Controller *controller, double value)
      : controller_(controller), value(value){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  double value;
};

/**
 * @brief The class for background color
 */
class BackgroundColorChange : public Command {
 public:
  /**
   * @brief The function handles initializing background color
   *
   * @param controller The controller
   * @param color The color
   * @return Background color
   */
  BackgroundColorChange(Controller *controller, QColor color)
      : controller_(controller), color(color){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  QColor color;
};

/**
 * @brief The class for edges color
 */
class EdgesColorChange : public Command {
 public:
  /**
   * @brief The function handles initializing edges color
   *
   * @param controller The controller
   * @param color The color
   * @return Edges color
   */
  EdgesColorChange(Controller *controller, QColor color)
      : controller_(controller), color(color){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  QColor color;
};

/**
 * @brief The class for vertices color
 */
class VerticesColorChange : public Command {
 public:
  /**
   * @brief The function handles initializing vertices color
   *
   * @param controller The controller
   * @param color The color
   * @return Vertices color
   */
  VerticesColorChange(Controller *controller, QColor color)
      : controller_(controller), color(color){};

  /**
   * @brief The function handles executing command
   *
   */
  virtual void execute();

 private:
  Controller *controller_;
  QColor color;
};

#endif  // SRC_MODEL_INCLUDE_COMMANDS_H
