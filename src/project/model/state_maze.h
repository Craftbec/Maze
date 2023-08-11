/// \file
#ifndef SRC_PROJECT_MODEL_STATE_MAZE_H_
#define SRC_PROJECT_MODEL_STATE_MAZE_H_
#include "general.h"
#include "maze.h"
#include "solution.h"
#include "trasformation_points.h"
namespace s21 {
/// @brief Class for tracking and changing labyrinth drawing points
class State_maze {
 public:
  /// @brief method to create maze from file
  /// @param filename file name
  void open_file(std::string filename);
  /// @brief method to generate maze
  /// @param rows number of rows
  /// @param cols number of columns
  void generate_labirint(int rows, int cols);
  /// @brief method for solving maze and saving to file
  /// @param rows number of rows
  /// @param cols number of columns
  /// @param start_i starting position axis x
  /// @param start_j starting positio axis y
  /// @param end_i finishing position axis x
  /// @param end_j finishing position axis y
  void solve_maze(int rows, int cols, int start_i, int start_j, int end_i,
                  int end_j);
  /// @brief access to the vertexes of the maze
  /// @return vertexes of the maze
  std::vector<float>& get_vertex_maze();
  /// @brief access to the indexes of the maze
  /// @return indexes of the maze
  std::vector<int>& get_index_maze();
  /// @brief access to the vertexes of the solution
  /// @return vertexes of the 'solution'
  std::vector<float>& get_vertex_solution();
  /// @brief access to the indexes of the solution
  /// @return indexes of the 'solution'
  std::vector<int>& get_index_solution();
  /// @brief cleaning vertices and solution indices
  void clear_solution();
  /// @brief access to number of rows
  /// @return number of rows
  int get_rows();
  /// @brief access to number of cols
  /// @return number of cols
  int get_cols();
  /// destructor destructor for matrix
  ~State_maze() { delete maze; }

 private:
  Rendering_points points_maze;
  Rendering_points points_solution;
  Maze* maze = nullptr;
};
}  // namespace s21
#endif  // SRC_PROJECT_MODEL_STATE_MAZE_H_
