#include "glwidget_maze.h"

GLWidget_maze::GLWidget_maze(QWidget *parent) : QOpenGLWidget{parent} {}

void GLWidget_maze::initializeGL() { glClearColor(1, 1, 1, 0); }

void GLWidget_maze::resizeGL(int w, int h) {}

void GLWidget_maze::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.005, 1.005, -1.005, 1.005, -2, 2);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_STIPPLE);
  glLineWidth(2);
  glColor3d(0, 0, 0);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, &state_maze.get_vertex_maze()[0]);
  glDrawElements(GL_LINES, state_maze.get_index_maze().size(), GL_UNSIGNED_INT,
                 &state_maze.get_index_maze()[0]);
  glColor3d(1, 0, 0);
  glVertexPointer(2, GL_FLOAT, 0, &state_maze.get_vertex_solution()[0]);
  glDrawElements(GL_LINES, state_maze.get_index_solution().size() - 1,
                 GL_UNSIGNED_INT, &state_maze.get_index_solution()[0]);
  glColor3d(1, 0, 0);
  glPointSize(size_dot);
  glEnable(GL_POINT_SMOOTH);
  glVertexPointer(2, GL_FLOAT, 0, &vertex_start_finish[0]);
  glDrawArrays(GL_POINTS, 0, vertex_start_finish.size() / 2);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void GLWidget_maze::mousePressEvent(QMouseEvent *event) {
  if (count_dot < 2 && rows > 0 && cols > 0) {
    float horizontal_size_widget = float(500) / float(cols);
    float vertical_size_widget = float(500) / float(rows);
    size_dot = std::min(horizontal_size_widget, vertical_size_widget) / 1.5;
    int widget_y = event->position().x() / horizontal_size_widget;
    int widget_x = event->position().y() / vertical_size_widget;
    x_y.push_back(widget_x);
    x_y.push_back(widget_y);
    float vertical_size = 2 / float(rows);
    float horizontal_size = 2 / float(cols);
    vertex_start_finish.push_back(
        -1 + (widget_y * horizontal_size + horizontal_size / 2));
    vertex_start_finish.push_back(
        1 - (widget_x * vertical_size + vertical_size / 2));
    count_dot++;
  } else {
    clear_maze();
  }
  if (count_dot == 2)
    state_maze.solve_maze(rows, cols, x_y[0], x_y[1], x_y[2], x_y[3]);
  update();
}

void GLWidget_maze::clear_maze() {
  count_dot = 0;
  vertex_start_finish.clear();
  x_y.clear();
  state_maze.clear_solution();
}

std::pair<int, int> GLWidget_maze::openFile(std::string filename) {
  state_maze.open_file(filename);
  rows = state_maze.get_rows();
  cols = state_maze.get_cols();
  std::pair<int, int> result = {rows, cols};
  clear_maze();
  update();
  return result;
}

void GLWidget_maze::maze_generate(int rows, int cols) {
  this->rows = rows;
  this->cols = cols;
  state_maze.generate_labirint(rows, cols);
  clear_maze();
  update();
}
