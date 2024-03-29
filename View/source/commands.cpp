#include "commands.h"

void ProjectionTypeChange::execute() {
  controller_->setProjectionType(index);
}

void EdgesTypeChange::execute() { controller_->setLineType(index); }

void DisplayTypeChange::execute() { controller_->setDisplayType(index); }

void VerticesSizeChange::execute() { controller_->setVertexSize(value); }

void EdgesThicknessChange::execute() { controller_->setLineWidth(value); }

void BackgroundColorChange::execute() {
  controller_->setBackgroundColorR(color.red() / 255.0f);
  controller_->setBackgroundColorG(color.green() / 255.0f);
  controller_->setBackgroundColorB(color.blue() / 255.0f);
}

void EdgesColorChange::execute() {
  controller_->setLineColorR(color.red() / 255.0f);
  controller_->setLineColorG(color.green() / 255.0f);
  controller_->setLineColorB(color.blue() / 255.0f);
}

void VerticesColorChange::execute() {
  controller_->setVerticesColorR(color.red() / 255.0f);
  controller_->setVerticesColorG(color.green() / 255.0f);
  controller_->setVerticesColorB(color.blue() / 255.0f);
}
