#include "viewer_widget.h"

viewer_widget::viewer_widget(QWidget *parent) : QOpenGLWidget{parent} {
  setFocusPolicy(Qt::ClickFocus);
}

void viewer_widget::setDependencies(Controller *c) { controller = c; }

viewer_widget::~viewer_widget() {}

void viewer_widget::changeModel() {
  controller->setModel();
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER,
               sizeof(unsigned int) * controller->getIndicesCount(),
               controller->getIndices(), GL_DYNAMIC_DRAW);
  ResetState();
  updateVertexBuffer();
  update();
}

void viewer_widget::initializeGL() {
  initializeOpenGLFunctions();
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
}

void viewer_widget::enableSettings() {
  glLineWidth(controller->getLineWidth());
  glClearColor(controller->getBackgroundColor().r(),
               controller->getBackgroundColor().g(),
               controller->getBackgroundColor().b(), 1.0f);
  glColor3f(controller->getLineColor().r(), controller->getLineColor().g(),
            controller->getLineColor().b());  // color of vertices
  glLineStipple(1, 0x0101);
  if (controller->toStipple()) {
    glEnable(GL_LINE_STIPPLE);
  } else {
    glDisable(GL_LINE_STIPPLE);
  }
  glPointSize(controller->getVertexSize());
  if (controller->toSmooth()) {
    glEnable(GL_POINT_SMOOTH);
  } else {
    glDisable(GL_POINT_SMOOTH);
  }

  controller->setModelMatrixes();

  if (controller->getModelInitialized()) {
    updateVertexBuffer();
  }
}

void viewer_widget::paintGL() {
  enableSettings();

  glClear(GL_COLOR_BUFFER_BIT);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

  if (controller->getModelInitialized()) {
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(controller->getLineColor().r(), controller->getLineColor().g(),
              controller->getLineColor().b());  // color of vertices
    glDrawElements(GL_TRIANGLES, controller->getIndicesCount(), GL_UNSIGNED_INT,
                   0);
    if (controller->toColor()) {
      glColor3f(controller->getVerticesColor().r(),
                controller->getVerticesColor().g(),
                controller->getVerticesColor().b());  // color of points
      glDrawArrays(GL_POINTS, 0, controller->getVerticesCount());
    }
    glDisableVertexAttribArray(0);
  }
}

void viewer_widget::updateVertexBuffer() {
  controller->updateModel();
  if (controller->getModelInitialized()) {
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(float) * 4 * controller->getVerticesCount(),
                 controller->getVerticesCopy(), GL_DYNAMIC_DRAW);
  }
}

void viewer_widget::updateSettings() {
  controller->saveSettings();
  update();
}

void viewer_widget::wheelEvent(QWheelEvent *event) {
  QPoint numDegrees = event->angleDelta() / 8;
  float old_scale = controller->getScale();

  if (numDegrees.y() >= 15) {  // Maximize
    controller->setScale(old_scale * 1.1);
  } else if (numDegrees.y() <= -15) {  // Minimize
    controller->setScale(old_scale * 0.9);
  }
  updateVertexBuffer();
  update();
  emit changeScaling();
  event->accept();
}

void viewer_widget::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    dragging = true;
    last_x = event->pos().x();
    last_y = event->pos().y();
  }
  event->accept();
}

void viewer_widget::mouseMoveEvent(QMouseEvent *event) {
  if ((event->buttons() & Qt::LeftButton) && dragging) {
    controller->setRotationAnglesY(controller->getRotationAnglesY() +
                                   ((event->pos().y() - last_y) / 100.0f));
    controller->setRotationAnglesX(controller->getRotationAnglesX() +
                                   ((event->pos().x() - last_x) / 100.0f));
    updateVertexBuffer();
    update();
    last_x = event->pos().x();
    last_y = event->pos().y();
  }
  emit changeRotationAngles();
  event->accept();
}

void viewer_widget::mouseReleaseEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton && dragging) {
    dragging = false;
  }
  event->accept();
}

void viewer_widget::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_W) {
    controller->setTranslationVectorY(controller->getTranslationVectorY() +
                                      0.1f);
  } else if (event->key() == Qt::Key_S) {
    controller->setTranslationVectorY(controller->getTranslationVectorY() -
                                      0.1f);
  } else if (event->key() == Qt::Key_A) {
    controller->setTranslationVectorX(controller->getTranslationVectorX() -
                                      0.1f);
  } else if (event->key() == Qt::Key_D) {
    controller->setTranslationVectorX(controller->getTranslationVectorX() +
                                      0.1f);
  } else {
    return;
  }
  emit changeTranslation();
  updateVertexBuffer();
  update();
}

void viewer_widget::RotationXChangeOutside(int value) {
  RotateX rotateX(controller);
  context.setStrategy(&rotateX);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeRotationAngles();
}

void viewer_widget::RotationYChangeOutside(int value) {
  RotateY rotateY(controller);
  context.setStrategy(&rotateY);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeRotationAngles();
}

void viewer_widget::RotationZChangeOutside(int value) {
  RotateZ rotateZ(controller);
  context.setStrategy(&rotateZ);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeRotationAngles();
}

void viewer_widget::ScalingChangeOutside(int value) {
  Scale scale(controller);
  context.setStrategy(&scale);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeScaling();
}

void viewer_widget::TranslationXChangeOutside(float value) {
  TranslationX translationX(controller);
  context.setStrategy(&translationX);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeTranslation();
}

void viewer_widget::TranslationYChangeOutside(float value) {
  TranslationY translationX(controller);
  context.setStrategy(&translationX);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeTranslation();
}

void viewer_widget::TranslationZChangeOutside(float value) {
  TranslationZ translationX(controller);
  context.setStrategy(&translationX);
  context.transform(value);
  updateVertexBuffer();
  update();
  emit changeTranslation();
}

void viewer_widget::ResetState() {
  controller->resetState();
  emit changeRotationAngles();
  emit changeScaling();
  emit changeTranslation();
}
