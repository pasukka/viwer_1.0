#include <QApplication>
#include <QStyleFactory>

#include "view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QCoreApplication::setAttribute(Qt::AA_DontUseNativeMenuBar);
  QApplication::setStyle(QStyleFactory::create("Fusion"));
  Settings settings;
  Parser parser;
  Model model(&parser);
  Controller controller(&model, &settings);
  View view(&controller);
  view.startEventLoop();
  return a.exec();
}
