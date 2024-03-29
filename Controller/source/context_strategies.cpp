#include "context_strategies.h"

void ContextStrategy::setStrategy(TransformStrategy *s) { strategy_ = s; }

void ContextStrategy::transform(float value) {
  if (strategy_) strategy_->transform(value);
}
