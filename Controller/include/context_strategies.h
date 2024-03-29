#if !defined(SRC_MODEL_INCLUDE_CONTEXT_STRATEGIES_H)
#define SRC_MODEL_INCLUDE_CONTEXT_STRATEGIES_H

/**
 * @file context_strategies.h
 * @author SevenStreams
 * @brief This file handles working with context strategies
 * @version 0.1
 * @date 2024-03-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "controller.h"
#include "matrix.h"
/**
 * @brief The Strategy interface
 */
class TransformStrategy {
 public:
  virtual ~TransformStrategy() = default;

  /**
   * @brief Transforms the given value
   *
   * @param value The value to be transformed
   */
  virtual void transform(float value) = 0;
};

/**
 * @brief The Context strategy class
 */
class ContextStrategy {
 public:
  ContextStrategy() = default;

  /**
   * @brief Constructs a ContextStrategy with the given strategy
   *
   * @param s The TransformStrategy to be set
   */
  ContextStrategy(TransformStrategy *s) : strategy_(s) {}

  /**
   * @brief Sets the transformation strategy for the ContextStrategy
   *
   * @param s The TransformStrategy to be set
   */
  void setStrategy(TransformStrategy *s);

  /**
   * @brief Transforms the given value using the strategy, if it exists
   *
   * @param value The value to be transformed
   */
  void transform(float value);

 private:
  TransformStrategy *strategy_;
};

#endif  // SRC_MODEL_INCLUDE_CONTEXT_STRATEGIES_H
