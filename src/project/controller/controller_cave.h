#ifndef SRC_PROJECT_CONTROLLER_CAVE_H_
#define SRC_PROJECT_CONTROLLER_CAVE_H_
#include "../model/state_cave.h"

namespace s21 {
/// @brief Cave Status Controller
class Controller_cave {
 public:
  /// @brief Default constructor
  /// creates a caves state class
  Controller_cave() : state_cave(new State_cave()){};
  /// destructor
  ~Controller_cave() { delete state_cave; };

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

 private:
  State_cave* state_cave;
};
}  // namespace s21
#endif  // SRC_PROJECT_CONTROLLER_CAVE_H_