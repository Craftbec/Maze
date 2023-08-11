#include "controller_cave.h"
using namespace s21;

void Controller_cave::open_file(int birth, int death, std::string filename) {
  state_cave->open_file(birth, death, filename);
}

void Controller_cave::generate_cave(int birth, int death, int rows, int cols,
                                    int chance) {
  state_cave->generate_cave(birth, death, rows, cols, chance);
}
bool Controller_cave::cellular_automation() {
  return state_cave->cellular_automation();
}

std::vector<float>& Controller_cave::get_vertex() {
  return state_cave->get_vertex();
}

std::vector<int>& Controller_cave::get_index() {
  return state_cave->get_index();
}

int Controller_cave::get_rows() { return state_cave->get_rows(); }

int Controller_cave::get_cols() { return state_cave->get_cols(); }

void Controller_cave::set_birth(int value) { state_cave->set_birth(value); }

void Controller_cave::set_death(int value) { state_cave->set_death(value); }