/// \file
#ifndef SRC_PROJECT_SOLUTION_H_
#define SRC_PROJECT_SOLUTION_H_
#include "general.h"
#include "maze.h"

namespace s21 {
/// @brief Class for solution maze and get this solution in matrix vision
class Solution {
 public:
  /// @brief Public constructor with parametrs
  /// @param maze Pointer on current maze
  /// @param start_i X coordinate start point
  /// @param start_j  Y coordinate start point
  /// @param end_i  X coordinate terminate point
  /// @param end_j  Y coordinate terminate point
  Solution(Maze *maze, int start_i, int start_j, int end_i, int end_j);

  /// @brief  Program entry point
  void start_program();
  /// @brief Method to get vector pair of point through which the path from
  /// the maze passes
  /// @return Vector pair of point through which the path from the maze passes
  std::vector<std::pair<int, int>> get_vector();

 private:
  /// @brief The method to get index vector which corresponds to the passed
  /// coordinates
  /// @param i  X coordinate
  /// @param j  Y coordinate
  /// @return Index vector which corresponds to the passed coordinates
  int pair_to_index(int i, int j);
  /// @brief The method to get pair of coordinate X and Y
  /// @param idx Index from vector for get pair
  /// @return Pair  of coordinate X and Y
  std::pair<int, int> index_to_pair(int idx);
  /// @brief  The method to get vector with values ​​equal to the number of
  /// steps to the end point
  /// @return Vector with values ​​equal to the number of steps to the end
  /// point
  std::vector<int> fill_path();
  /// @brief The method to get index cell which is on top of current
  /// @param index  The pair of coordinate X and Y
  /// @return  Index cell which is on top of current
  int up(std::pair<int, int> index);
  /// @brief The method to get index cell which is lower than current
  /// @param index  The pair of coordinate X and Y
  /// @return  Index cell which is lower than current
  int down(std::pair<int, int> index);
  /// @brief The method to get index cell which is more to the left than
  /// current
  /// @param index  The pair of coordinate X and Y
  /// @return  Index cell which is more to the left than current
  int left(std::pair<int, int> index);
  /// @brief The method for get index cell which is more to the right than
  /// current
  /// @param index  The pair of coordinate X and Y
  /// @return  Index cell which is more to the right than current
  int right(std::pair<int, int> index);
  /// @brief The method to fill a vector of pairs with coordinates to step
  /// through the path
  /// @param matrix Vector with values ​​equal to the number of steps to the
  /// end point
  void make_path_in_vector(std::vector<int> matrix);

  /// @brief The pointer to current maze
  Maze *maze_;
  /// @brief Vector of pairs with coordinates to step through the path
  std::vector<std::pair<int, int>> solution_;
  /// @brief The coordinate of the start points of the maze
  std::pair<int, int> start;
  /// @brief The coordinates of the end points of the maze
  std::pair<int, int> end;
};
}  // namespace s21
#endif  // SRC_PROJECT_SOLUTION_H_
