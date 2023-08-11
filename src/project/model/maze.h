/// \file
#ifndef SRC_PROJECT_MAZE_H_
#define SRC_PROJECT_MAZE_H_
#include "general.h"

namespace s21 {

/// @brief Class for get matrices with walls for painting maze
class Maze {
 public:
  /// @brief Public constructor with parametrs
  /// @param rows_  Number rows in matrices
  /// @param cols_  Number columns in matrices
  Maze(int rows_ = 0, int cols_ = 0);

  /// @brief Method to get number rows
  /// @return Number rows
  int get_rows();
  /// @brief Method to get number columns
  /// @return Number columns
  int get_cols();
  /// @brief Method to get structure with matrices horizontal and vertical
  /// walls and size this matrices
  /// @return Structure with matrices horizontal and vertical walls and size
  /// this matrices
  Matrix_maze get_matrix();
  /// @brief The method to get matrix vertical walls
  /// @return Matrix vertical walls
  std::vector<char> get_vertical_matrix();
  /// @brief The Method to get matrix horizintal walls
  /// @return Matrix horizontal walls
  std::vector<char> get_horizontal_matrix();
  /// @brief The method to generate two matrices for getting perfect maze and
  /// write them in file
  void generate_maze();
  /// @brief  The method to filling matrices horizontal and vertical walls from
  /// file
  /// @param path_to_file Path to file
  void read_from_file(std::string path_to_file);

 private:
  /// @brief The method for generate name of file
  /// @return String with file name
  std::string name_generate();
  /// @brief The method for begin initialization row zero value for use The
  /// Eller algorithm
  void fill_empty_value();
  /// @brief The method for generation unique value for fill row at using The
  /// Eller algorithm
  void unique_value();
  /// @brief The method to get random bool(1 or 0)
  /// @return Received value
  bool random_bool();
  /// @brief The method for processing the construction of the right walls
  void right_borders();
  /// @brief The method for merge sets into one set
  /// @param i  Index current element
  /// @param el Set element
  void union_of_sets(int i, int el);
  /// @brief The method for processing the construction of the bottom walls
  void bottom_line();
  /// @brief  The number counter of set element
  /// @param num  Element for count
  /// @return Number of finded elements
  int number_of_cells(int num);
  /// @brief The method for processing last row (The Eller algorith)
  void adding_endLine();
  /// @brief The method for check and change last row (The Eller algorith)
  void check_end();
  /// @brief The method for check and delete horizontal wall (The Eller
  /// algorith)
  /// @param row  Index of row for check
  void wall_check(int row);
  /// @brief  The method for count number elements in this row to decide whether
  /// to remove the side wall
  /// @param element  Item to search
  /// @param row  Search line
  /// @return Number finded elements
  int count_wall(int element, int row);
  /// @brief The method for delete walls in passed row
  /// @param row  The row in which to remove all the walls
  void wall_removal(int row);
  /// @brief The method for exists file with data current maze
  /// @param path_to_file Path to file
  void writing_to_file(std::string path_to_file);

  /// @brief  The variable to store unique values(for using in The Eller
  /// algorithm)
  int counter_;
  /// @brief The vector current line(for using in The Eller algorithm)
  std::vector<int> sideLine_;
  /// @brief  The structure with the saved matrix for drawing
  Matrix_maze matr_;
};
}  // namespace s21
#endif  // SRC_PROJECT_MAZE_H_
