#include "strategies.h"

void RotateX::transform(float value) {
  controller->setRotationAnglesX(value * M_PI / 180.0f);
}

void RotateY::transform(float value) {
  controller->setRotationAnglesY(value * M_PI / 180.0f);
}

void RotateZ::transform(float value) {
  controller->setRotationAnglesZ(value * M_PI / 180.0f);
}

void Scale::transform(float value) {
  controller->setScale(value / FACTOR_SCALE_SLIDER);
}

void TranslationX::transform(float value) {
  controller->setTranslationVectorX(value);
}

void TranslationY::transform(float value) {
  controller->setTranslationVectorY(value);
}

void TranslationZ::transform(float value) {
  controller->setTranslationVectorZ(value);
}
