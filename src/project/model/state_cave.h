/// \file
#ifndef SRC_PROJECT_MODEL_STATE_CAVE_H_
#define SRC_PROJECT_MODEL_STATE_CAVE_H_
#include "cave.h"
#include "general.h"
#include "trasformation_points.h"
namespace s21 {
/// @brief Сlass for tracking and changing the state of cave points
class State_cave {
 public:
  /// @brief method to create maze from file
  /// @param birth cell birth condition
  /// @param death cell death condition
  /// @param filename file name
  void open_file(int birth, int death, std::string filename);
  /// @brief method for generating caves and saving to file
  /// @param birth cell birth condition
  /// @param death cell death condition
  /// @param rows number of rows in matrix
  /// @param cols number of cols in matrix
  void generate_cave(int birth, int death, int rows, int cols, int chance);
  /// @brief The method for next step recalculation live end death cells end
  /// change current field matrix
  /// @return Bool value may or may not continue to change the field matrix
  bool cellular_automation();
  /// @brief access to the vertexes of the solution
  /// @return vertexes of the cave
  std::vector<float>& get_vertex();
  /// @brief access to the indexes of the solution
  /// @return indexes of the cave
  std::vector<int>& get_index();
  /// @brief access to the count rows in matrix
  /// @return count rows in matrix
  int get_rows();
  /// @brief access to the count cols in matrix
  /// @return count cols in matrix
  int get_cols();
  /// @brief The method for setting field birth_
  /// @param value Value for setting field birth_
  void set_birth(int value);
  /// @brief The method for setting field death_
  /// @param value Value for setting field death_
  void set_death(int value);
  /// @brief destructor for clear field cave
  ~State_cave() { delete cave; }

 private:
  /// @brief save new matrix
  void set_matrix();
  Rendering_points matrix_cave;
  Cave* cave = nullptr;
  int rows = 0;
  int cols = 0;
};
}  // namespace s21
#endif  // SRC_PROJECT_MODEL_STATE_CAVE_H_
