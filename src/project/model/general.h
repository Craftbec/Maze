/// \file
#ifndef SRC_MODEL_GENERAL_H_
#define SRC_MODEL_GENERAL_H_
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <queue>
#include <thread>
#include <vector>

enum type_state {
  state_maze = 0,
  state_cave = 1,
};

struct Rendering_points {
  std::vector<float> vertex;
  std::vector<int> index;
};

/// @brief  The structure with matrix indexes for painting
struct Matrix_cave {
  /// @brief Number rows in matrix
  int rows;
  /// @brief Number columns in matrix
  int cols;
  /// @brief The matrix cave
  std::vector<char> matrix;
};

struct Matrix_solutions {
  int rows, cols;
  std::vector<char> matrix;
};

/// @brief  The structure with matrices indexes for painting
struct Matrix_maze {
  /// @brief Number rows in matrices
  int rows;
  /// @brief Number columns in matrices
  int cols;
  /// @brief Matrix vertical walls
  std::vector<char> vertical_wall;
  /// @brief Matrix horizontal walls
  std::vector<char> horizontal_wall;
};

#endif  // SRC_MODEL_GENERAL_H_