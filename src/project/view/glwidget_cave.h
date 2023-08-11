#ifndef GLWIDGET_CAVE_H
#define GLWIDGET_CAVE_H
#define GL_SILENCE_DEPRECATION
#include <QElapsedTimer>
#include <QEventLoop>
#include <QTimer>

#include "../controller/controller_cave.h"
#include "QOpenGLWidget"

class GLWidget_cave : public QOpenGLWidget {
 public:
  explicit GLWidget_cave(QWidget *parent = nullptr);

 public slots:
  std::pair<int, int> openFile(int birth, int death, std::string filename);
  void generateCave(int birth, int death, int rows, int cols, int chance);
  void start(int milliseconds);
  bool next();
  void update_slot();
  void set_death(int value);
  void set_birth(int value);

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  s21::Controller_cave state_cave;
  QTimer *timer;
};

#endif  // GLWIDGET_CAVE_H
