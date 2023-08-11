#include "glwidget_cave.h"

GLWidget_cave::GLWidget_cave(QWidget *parent) : QOpenGLWidget{parent} {
  timer = new QTimer(this);
}

std::pair<int, int> GLWidget_cave::openFile(int birth, int death,
                                            std::string filename) {
  state_cave.open_file(birth, death, filename);
  update();
  std::pair<int, int> result = {state_cave.get_rows(), state_cave.get_cols()};
  return result;
}

void GLWidget_cave::generateCave(int birth, int death, int rows, int cols,
                                 int chance) {
  state_cave.generate_cave(birth, death, rows, cols, chance);
  update();
}

void GLWidget_cave::start(int milliseconds) {}

bool GLWidget_cave::next() {
  bool result = state_cave.cellular_automation();
  update();
  return result;
}

void GLWidget_cave::update_slot() {
  std::thread second_state([&] { update(); });
  second_state.join();
}

void GLWidget_cave::set_death(int value) { state_cave.set_death(value); }

void GLWidget_cave::set_birth(int value) { state_cave.set_birth(value); }

void GLWidget_cave::initializeGL() { glClearColor(1, 1, 1, 0); }

void GLWidget_cave::resizeGL(int w, int h) {}

void GLWidget_cave::paintGL() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.005, 1.005, -1.005, 1.005, -2, 2);
  glEnable(GL_BLEND);
  glEnable(GL_LINE_STIPPLE);
  glLineWidth(2);
  glColor3d(0, 0, 0);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 0, &state_cave.get_vertex()[0]);
  glDrawElements(GL_QUADS, state_cave.get_index().size() / 2, GL_UNSIGNED_INT,
                 &state_cave.get_index()[0]);
  glDisableClientState(GL_VERTEX_ARRAY);
}
