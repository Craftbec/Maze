/// \file
#include "state_cave.h"

#include "general.h"
using namespace s21;

void State_cave::open_file(int birth, int death, std::string filename) {
  if (cave != nullptr) delete cave;
  cave = new Cave(birth, death);
  cave->start_program(filename);
  set_matrix();
}

void State_cave::generate_cave(int birth, int death, int rows, int cols,
                               int chance) {
  if (cave != nullptr) delete cave;
  cave = new Cave(birth, death, chance);
  cave->cave_generator(rows, cols);
  set_matrix();
}

void State_cave::set_matrix() {
  Matrix_cave tmp = cave->get_matrix();
  rows = tmp.rows;
  cols = tmp.cols;
  Trasformation_points points(tmp);
  matrix_cave = points.get_points();
}

bool State_cave::cellular_automation() {
  if (cave == nullptr) return false;
  bool result = cave->cellular_automation();
  set_matrix();
  return result;
}

std::vector<float>& State_cave::get_vertex() { return matrix_cave.vertex; }

std::vector<int>& State_cave::get_index() { return matrix_cave.index; }

int State_cave::get_rows() { return rows; }

int State_cave::get_cols() { return cols; }

void State_cave::set_birth(int value) {
  if (cave != nullptr) cave->set_birth(value);
}

void State_cave::set_death(int value) {
  if (cave != nullptr) cave->set_death(value);
}
