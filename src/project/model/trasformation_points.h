/// \file
#ifndef SRC_PROJECT_MODEL_TRANSFORMATION_POINTS_H_
#define SRC_PROJECT_MODEL_TRANSFORMATION_POINTS_H_
#include "general.h"
namespace s21 {
/// @brief class for transforming points into vertices
class Trasformation_points {
 public:
  /// @brief Public constructor for transforming labyrinth points
  /// @param other matrix with labyrinth
  Trasformation_points(Matrix_maze other) {
    matrix_maze = other;
    calculate_size_maze();
    add_vertical_coord();
    add_horizontal_coord();
    add_left_and_top_border();
  }

  /// @brief Public constructor for converting cave points
  /// @param other matrix with cave
  Trasformation_points(Matrix_cave other) {
    matrix_cave = other;
    calculate_size_cave();
    add_cave();
  }

  /// @brief constructor for converting points 'solution'
  /// @param other pairs with vertices "X" & "Y"
  /// @param rows number of rows in matrix
  /// @param rows number of cols in matrix
  Trasformation_points(std::vector<std::pair<int, int>> other, int rows,
                       int cols) {
    solution = other;
    solution_rows = rows;
    solution_cols = cols;
    calculate_size_solution();
    add_solutions();
  }

  /// @brief access to vertices and indices for drawing
  /// @return structure of type Rendering_points
  Rendering_points get_points() { return points; }

 private:
  /// @brief transformation to vertical drawing lines
  void add_vertical_coord();
  /// @brief transformation to horizontal drawing lines
  void add_horizontal_coord();
  /// @brief adding a top and left border
  void add_left_and_top_border();
  /// @brief transformation into pairs of indexes for rendering
  void add_cave();
  /// @brief rendering solution transformation
  void add_solutions();
  /// @brief calculation of the size of the 'maze' lines
  void calculate_size_maze();
  /// @brief calculation of the size of the 'cave' lines
  void calculate_size_cave();
  /// @brief calculation of the size of the 'solution' lines
  void calculate_size_solution();

  int solution_rows;
  int solution_cols;
  float vertical_size;
  float horizontal_size;
  Matrix_maze matrix_maze;
  Matrix_cave matrix_cave;
  std::vector<std::pair<int, int>> solution;
  Rendering_points points;
};
}  // namespace s21
#endif  // SRC_PROJECT_MODEL_TRANSFORMATION_POINTS_H_
