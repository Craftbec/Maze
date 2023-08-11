#include "controller_maze.h"
using namespace s21;

void Controller_maze::open_file(std::string filename) {
  state_maze->open_file(filename);
}
std::vector<float>& Controller_maze::get_vertex_maze() {
  return state_maze->get_vertex_maze();
}

std::vector<int>& Controller_maze::get_index_maze() {
  return state_maze->get_index_maze();
}

std::vector<float>& Controller_maze::get_vertex_solution() {
  return state_maze->get_vertex_solution();
}

std::vector<int>& Controller_maze::get_index_solution() {
  return state_maze->get_index_solution();
}
void Controller_maze::clear_solution() { return state_maze->clear_solution(); }
void Controller_maze::generate_labirint(int rows, int cols) {
  state_maze->generate_labirint(rows, cols);
}
void Controller_maze::solve_maze(int rows, int cols, int start_i, int start_j,
                                 int end_i, int end_j) {
  state_maze->solve_maze(rows, cols, start_i, start_j, end_i, end_j);
}
int Controller_maze::get_rows() { return state_maze->get_rows(); }
int Controller_maze::get_cols() { return state_maze->get_cols(); }
