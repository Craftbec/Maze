/// \file
#include "trasformation_points.h"
using namespace s21;

void Trasformation_points::calculate_size_maze() {
  vertical_size = 2 / float(matrix_maze.rows);
  horizontal_size = 2 / float(matrix_maze.cols);
}

void Trasformation_points::calculate_size_cave() {
  vertical_size = 2 / float(matrix_cave.rows);
  horizontal_size = 2 / float(matrix_cave.cols);
}

void Trasformation_points::calculate_size_solution() {
  vertical_size = 2 / float(solution_rows);
  horizontal_size = 2 / float(solution_cols);
}

void Trasformation_points::add_solutions() {
  for (int i = 0; i < (int)solution.size(); i++) {
    points.vertex.push_back(
        -1 + (solution[i].second * horizontal_size + horizontal_size / 2));
    points.vertex.push_back(
        1 - (solution[i].first * vertical_size + vertical_size / 2));
  }

  for (int i = 0; i < (int)points.vertex.size() / 2; i++) {
    points.index.push_back(i);
    points.index.push_back(i + 1);
  }
}

void Trasformation_points::add_vertical_coord() {
  for (int i = 0; i < (int)matrix_maze.vertical_wall.size(); i++) {
    int count = 0;
    int count_rows = i / matrix_maze.cols;
    for (int end = i + matrix_maze.cols; i < end; i++) {
      count++;
      if (matrix_maze.vertical_wall[i] == '1') {
        float x = -1 + (horizontal_size * count);
        float y_1 = 1 - (vertical_size * count_rows);
        float y_2 = y_1 - vertical_size;
        points.vertex.push_back(x);
        points.vertex.push_back(y_1);
        points.vertex.push_back(x);
        points.vertex.push_back(y_2);
        points.index.push_back(points.vertex.size() / 2 - 2);
        points.index.push_back(points.vertex.size() / 2 - 1);
      }
    }
    i--;
  }
}

void Trasformation_points::add_horizontal_coord() {
  for (int i = 0; i < (int)matrix_maze.horizontal_wall.size(); i++) {
    int count = 0;
    int count_rows = i / matrix_maze.cols;
    for (int end = i + matrix_maze.cols; i < end; i++) {
      if (matrix_maze.horizontal_wall[i] == '1') {
        float y = 1 - (vertical_size * (count_rows + 1));
        float x_1 = -1 + (horizontal_size * count);
        float x_2 = x_1 + horizontal_size;
        points.vertex.push_back(x_1);
        points.vertex.push_back(y);
        points.vertex.push_back(x_2);
        points.vertex.push_back(y);
        points.index.push_back(points.vertex.size() / 2 - 2);
        points.index.push_back(points.vertex.size() / 2 - 1);
      }
      count++;
    }
    i--;
  }
}

void Trasformation_points::add_left_and_top_border() {
  points.vertex.push_back(-1);
  points.vertex.push_back(-1);
  points.vertex.push_back(-1);
  points.vertex.push_back(1);
  points.vertex.push_back(1);
  points.vertex.push_back(1);
  points.index.push_back(points.vertex.size() / 2 - 3);
  points.index.push_back(points.vertex.size() / 2 - 2);
  points.index.push_back(points.vertex.size() / 2 - 2);
  points.index.push_back(points.vertex.size() / 2 - 1);
}

void Trasformation_points::add_cave() {
  for (int i = 0; i < (int)matrix_cave.matrix.size(); i++) {
    int count = 0;
    int count_rows = i / matrix_cave.cols;
    for (int end = i + matrix_cave.cols; i < end; i++) {
      if (matrix_cave.matrix[i] == '1') {
        float y_1 = 1 - (vertical_size * (count_rows));
        float y_2 = y_1 - vertical_size;
        float x_1 = -1 + (horizontal_size * count);
        float x_2 = x_1 + horizontal_size;
        points.vertex.push_back(x_1);
        points.vertex.push_back(y_1);
        points.vertex.push_back(x_1);
        points.vertex.push_back(y_2);
        points.vertex.push_back(x_2);
        points.vertex.push_back(y_2);
        points.vertex.push_back(x_2);
        points.vertex.push_back(y_1);
      }
      count++;
    }
    i--;
  }

  for (int i = 0; i < (int)points.vertex.size(); i++) {
    points.index.push_back(i);
  }
}
