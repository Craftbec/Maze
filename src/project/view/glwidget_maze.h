#ifndef GLWIDGET_H
#define GLWIDGET_H
#define GL_SILENCE_DEPRECATION
#include <QMouseEvent>
#include <QOpenGLWidget>

#include "../controller/controller_maze.h"
#include "mainwindow.h"

class GLWidget_maze : public QOpenGLWidget {
 public:
  explicit GLWidget_maze(QWidget *parent = nullptr);

 public slots:
  std::pair<int, int> openFile(std::string filename);
  void maze_generate(int rows, int cols);

 protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

 private:
  s21::Controller_maze state_maze;
  int rows = 0;
  int cols = 0;
  std::vector<float> vertex_start_finish;
  float size_dot;
  int count_dot = 0;
  std::vector<int> x_y;
  void clear_maze();

 private slots:
  void mousePressEvent(QMouseEvent *event) override;
};

#endif  // GLWIDGET_H
