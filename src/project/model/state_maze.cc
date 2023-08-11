/// \file
#include "state_maze.h"

namespace s21 {
void State_maze::open_file(std::string filename) {
  if (maze != nullptr) delete maze;
  maze = new Maze();
  maze->read_from_file(filename);
  Trasformation_points points(maze->get_matrix());
  points_maze = points.get_points();
}

std::vector<float>& State_maze::get_vertex_maze() { return points_maze.vertex; }

std::vector<int>& State_maze::get_index_maze() { return points_maze.index; }

std::vector<float>& State_maze::get_vertex_solution() {
  return points_solution.vertex;
}

std::vector<int>& State_maze::get_index_solution() {
  return points_solution.index;
}

int State_maze::get_rows() { return maze->get_rows(); }

int State_maze::get_cols() { return maze->get_cols(); }

void State_maze::clear_solution() {
  points_solution.vertex.clear();
  points_solution.index.clear();
}

void State_maze::generate_labirint(int rows, int cols) {
  if (maze != nullptr) delete maze;
  maze = new Maze(rows, cols);
  maze->generate_maze();
  Trasformation_points points(maze->get_matrix());
  points_maze = points.get_points();
}

void State_maze::solve_maze(int rows, int cols, int start_i, int start_j,
                            int end_i, int end_j) {
  Solution solution(maze, start_i, start_j, end_i, end_j);
  solution.start_program();
  Trasformation_points points(solution.get_vector(), rows, cols);
  points_solution = points.get_points();
}

}  // namespace s21
