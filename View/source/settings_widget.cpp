#include "settings_widget.h"

#include "ui_settings_widget.h"

Settings_widget::Settings_widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Settings_widget) {
  ui->setupUi(this);
}

Settings_widget::Settings_widget(viewer_widget *view_field,
                                      Controller *controller)
    : Settings_widget() {
  view_field_ = view_field;
  commandManager = new CommandManager();
  controller_ = controller;
  ui->thickness_edges_box->setButtonSymbols(QAbstractSpinBox::PlusMinus);
  ui->size_vertices_box->setButtonSymbols(QAbstractSpinBox::PlusMinus);

  controller_->uploadSettings();
  InitializeElements();

  connect(ui->Type_proj_box, SIGNAL(currentIndexChanged(int)),
          SLOT(ProjectionTypeChanged(int)));
  connect(ui->Type_edg_box, SIGNAL(currentIndexChanged(int)),
          SLOT(EdgesTypeChanged(int)));
  connect(ui->Display_edg_box, SIGNAL(currentIndexChanged(int)),
          SLOT(DisplayTypeChanged(int)));

  connect(ui->background_color_button, SIGNAL(released()),
          SLOT(BackgroundColorButtonClicked()));
  connect(ui->edges_color_button, SIGNAL(released()),
          SLOT(EdgesColorButtonClicked()));
  connect(ui->vertices_color_button, SIGNAL(released()),
          SLOT(VerticesColorButtonClicked()));

  connect(ui->thickness_edges_box, SIGNAL(valueChanged(double)),
          SLOT(EdgesThicknessChanged(double)));
  connect(ui->size_vertices_box, SIGNAL(valueChanged(double)),
          SLOT(VerticesSizeChanged(double)));
  connect(this, SIGNAL(SettingsChanged()), view_field_, SLOT(updateSettings()));
}

Settings_widget::~Settings_widget() {
  delete ui;
  controller_->saveSettings();
}

void Settings_widget::ProjectionTypeChanged(int index) {
  commandManager->setCommand(new ProjectionTypeChange(controller_, index));
  commandManager->run();
  emit SettingsChanged();
}

void Settings_widget::EdgesTypeChanged(int index) {
  commandManager->setCommand(new EdgesTypeChange(controller_, index));
  commandManager->run();
  emit SettingsChanged();
}

void Settings_widget::DisplayTypeChanged(int index) {
  commandManager->setCommand(new DisplayTypeChange(controller_, index));
  commandManager->run();
  emit SettingsChanged();
}

void Settings_widget::VerticesSizeChanged(double value) {
  commandManager->setCommand(new VerticesSizeChange(controller_, value));
  commandManager->run();
  emit SettingsChanged();
}

void Settings_widget::EdgesThicknessChanged(double value) {
  commandManager->setCommand(new EdgesThicknessChange(controller_, value));
  commandManager->run();
  emit SettingsChanged();
}

void Settings_widget::BackgroundColorButtonClicked() {
  QColor color = QColorDialog::getColor();
  commandManager->setCommand(new BackgroundColorChange(controller_, color));
  commandManager->run();
  ChangeFrameColor(ui->background_color_frame, color.red(), color.green(),
                   color.blue());
  emit SettingsChanged();
}

void Settings_widget::EdgesColorButtonClicked() {
  QColor color = QColorDialog::getColor();
  commandManager->setCommand(new EdgesColorChange(controller_, color));
  commandManager->run();
  ChangeFrameColor(ui->edges_color_frame, color.red(), color.green(),
                   color.blue());
  emit SettingsChanged();
}

void Settings_widget::VerticesColorButtonClicked() {
  QColor color = QColorDialog::getColor();
  commandManager->setCommand(new VerticesColorChange(controller_, color));
  commandManager->run();
  ChangeFrameColor(ui->vertices_color_frame, color.red(), color.green(),
                   color.blue());
  emit SettingsChanged();
}

void Settings_widget::ChangeFrameColor(QFrame *frame, int red, int green,
                                            int blue) {
  char str[40];
  sprintf(str, "background-color: rgb(%d,%d,%d)", red, green, blue);
  frame->setStyleSheet(str);
}

void Settings_widget::InitializeElements() {
  ChangeFrameColor(ui->background_color_frame,
                   controller_->getBackgroundColor().r() * 255,
                   controller_->getBackgroundColor().g() * 255,
                   controller_->getBackgroundColor().b() * 255);
  ChangeFrameColor(ui->edges_color_frame, controller_->getLineColor().r() * 255,
                   controller_->getLineColor().g() * 255,
                   controller_->getLineColor().b() * 255);
  ChangeFrameColor(ui->vertices_color_frame,
                   controller_->getVerticesColor().r() * 255,
                   controller_->getVerticesColor().g() * 255,
                   controller_->getVerticesColor().b() * 255);
  ui->thickness_edges_box->setValue(controller_->getLineWidth());
  ui->size_vertices_box->setValue(controller_->getVertexSize());
  ui->Type_edg_box->setCurrentIndex(controller_->getLineTypeIndex());
  ui->Display_edg_box->setCurrentIndex(controller_->getDisplayTypeIndex());
  ui->Type_proj_box->setCurrentIndex(controller_->getProjectionTypeIndex());
}
