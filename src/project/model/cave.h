/// \file
#ifndef SRC_PROJECT_MODEL_CAVE_H_
#define SRC_PROJECT_MODEL_CAVE_H_
#include "general.h"

namespace s21 {

/// @brief Class for creating random matrix for painting 'cave'
class Cave {
 public:
  /// @brief Public constructor with parametrs
  /// @param birth The number of adjacent cells to respawn
  /// @param death  The number of neighboring cells is less than the number of
  /// which the current one dies
  /// @param chance The chance for the starting initialization of the cell
  Cave(int birth, int death, int chance = 0);

  /// @brief The method for setting field birth_
  /// @param value Value for setting field birth_
  void set_birth(int value) { birth_ = value; }
  /// @brief The method for setting field death_
  /// @param value Value for setting field death_
  void set_death(int value) { death_ = value; }
  /// @brief The method to get structure with matrix values and size cave
  /// @return Structure with matrix values and size cave
  Matrix_cave get_matrix();
  /// @brief The method for step_by_step automation change matrix for painting
  /// cave
  /// @param N Sleep value(in milliseconds)
  void timer(int N);
  /// @brief The method for next step recalculation live end death cells end
  /// change current field matrix
  /// @return Bool value may or may not continue to change the field matrix
  bool cellular_automation();
  /// @brief  First method, program entry point(if file is exist)
  /// @param path_to_file Path to file
  void start_program(std::string path_to_file);
  /// @brief  First method, program entry point(if need generation cave)
  /// @param rows The number rows
  /// @param cols The number columns
  void cave_generator(int rows, int cols);

 private:
  /// @brief The method to get bool value
  /// @return Random bool value
  bool random_bool();
  /// @brief  The method for set rows and cols values
  /// @param line The string with values for fill fields rows and cols
  void set_rows_cols(std::string line);
  /// @brief The method for fill field matrix
  /// @param str  The string with values for fill field matrix
  void set_matrix(std::string str);
  /// @brief The method for count cells around current cell
  /// @param i Index location current cell
  /// @return Number cells around current cell
  int living_cells(int i);

  /// @brief  Field to get values minimal living cells around for cell
  /// revitalization
  int birth_;
  /// @brief Field to get values minimal living cells around for killing
  /// current cell
  int death_;
  /// @brief Field to get values chance for the starting initialization of the
  /// cell
  int chance_;
  /// @brief Field with data for painting cave
  Matrix_cave cave_;
};
}  // namespace s21
#endif  // SRC_PROJECT_MODEL_CAVE_H_
