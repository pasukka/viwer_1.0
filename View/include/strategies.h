#if !defined(SRC_MODEL_INCLUDE_STRATEGIES_H)
#define SRC_MODEL_INCLUDE_STRATEGIES_H

#define FACTOR_SCALE_SLIDER 50.0f

#include "context_strategies.h"

/**
 * @file strategies.h
 * @author SevenStreams
 * @brief This file handles working with different strategies of transforming
 * model
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

/**
 * @brief Class for rotating an object around the X-axis.
 */
class RotateX : public TransformStrategy {
 public:
  /**
   * @brief Constructor for RotateX class.
   *
   * @param c pointer to the controller
   */
  RotateX(Controller *c) : controller(c) {}

  /**
   * @brief Transforms the RotateX object by setting rotation angles around the
   * X-axis.
   *
   * @param value the value to rotate by in degrees
   *
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

/**
 * @brief Class for rotating an object around the Y-axis.
 */
class RotateY : public TransformStrategy {
 public:
  /**
   * @brief Constructor for RotateY class.
   *
   * @param c pointer to the controller
   */
  RotateY(Controller *c) : controller(c) {}

  /**
   * @brief Transforms the RotateY object by setting rotation angles around the
   * Y-axis.
   *
   * @param value the amount to rotate in degrees
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

/**
 * @brief Class for rotating an object around the Z-axis.
 */
class RotateZ : public TransformStrategy {
 public:
  /**
   * @brief Constructor for RotateZ class.
   *
   * @param c pointer to the controller
   */
  RotateZ(Controller *c) : controller(c) {}

  /**
   * @brief Transforms the RotateZ object by setting rotation angles around the
   * Z-axis.
   *
   * @param value the value to set as the rotation angles Z
   *
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

/**
 * @brief Class for applying a scale transformation to an object.
 */
class Scale : public TransformStrategy {
 public:
  /**
   * @brief Constructor for Scale class.
   *
   * @param c pointer to the controller
   */
  Scale(Controller *c) : controller(c) {}

  /**
   * @brief Applies a transformation to the Scale object.
   *
   * @param value the value to apply transformation
   *
   * @throws ErrorType if controller is not initialized
   */
  void transform(float value) override;

 private:
  Controller *controller;
};
/**
 * @brief Class for applying translation along the X-axis.
 */
class TranslationX : public TransformStrategy {
 public:
  /**
   * @brief Constructor for TranslationX class.
   *
   * @param c pointer to the controller
   */
  TranslationX(Controller *c) : controller(c) {}

  /**
   * @brief Transform the value for TranslationX.
   *
   * @param value the value to set for translation vector X
   *
   * @throws ErrorType if there is an error setting the translation vector X
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

/**
 * @brief Class for applying translation along the Y-axis.
 */
class TranslationY : public TransformStrategy {
 public:
  /**
   * @brief Constructor for TranslationY class.
   *
   * @param c pointer to the controller
   */
  TranslationY(Controller *c) : controller(c) {}

  /**
   * @brief Transforms the value by setting the translation vector on the
   * y-axis.
   *
   * @param value the value to be transformed
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

/**
 * @brief Class for applying translation along the Z-axis.
 */
class TranslationZ : public TransformStrategy {
 public:
  /**
   * @brief Constructor for TranslationZ class.
   *
   * @param c pointer to the controller
   */
  TranslationZ(Controller *c) : controller(c) {}

  /**
   * @brief Transforms the translation vector in the Z direction.
   *
   * @param value the new value for the translation in the Z direction
   *
   */
  void transform(float value) override;

 private:
  Controller *controller;
};

#endif  // SRC_MODEL_INCLUDE_STRATEGIES_H
