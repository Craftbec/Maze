#include <gtest/gtest.h>

#include "../project/controller/controller_cave.h"
#include "../project/controller/controller_maze.h"

template <typename T>
void output(std::vector<T> nums) {
  for (size_t i = 0; i < nums.size(); i++) {
    std::cout << nums[i] << ", ";
  }
  std::cout << "\n";
}

TEST(Controller_maze, drawpoints_maze) {
  s21::Controller_maze tmp;
  tmp.open_file("./tests/4x4.maze");
  std::vector<float> vertexes = {
      1,  1,    1,    0.5, -0.5, 0.5, -0.5, 0,   1,    0.5, 1,    0,  -0.5,
      0,  -0.5, -0.5, 0.5, 0,    0.5, -0.5, 1,   0,    1,   -0.5, 1,  -0.5,
      1,  -1,   -0.5, 0.5, 0,    0.5, 0,    0.5, 0.5,  0.5, 0,    0,  0.5,
      0,  -0.5, -0.5, 0,   -0.5, 0,   -0.5, 0.5, -0.5, 0.5, -0.5, 1,  -0.5,
      -1, -1,   -0.5, -1,  -0.5, -1,  0,    -1,  0,    -1,  0.5,  -1, 0.5,
      -1, 1,    -1,   -1,  -1,   -1,  1,    1,   1};
  std::vector<int> indexes = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                              30, 31, 32, 33, 34, 35, 35, 36};
  EXPECT_EQ(vertexes, tmp.get_vertex_maze());
  EXPECT_EQ(indexes, tmp.get_index_maze());
}

TEST(Controller_maze, drawpoints_solutions) {
  s21::Controller_maze tmp;
  tmp.open_file("./tests/4x4.maze");
  tmp.solve_maze(4, 4, 0, 0, 3, 3);
  std::vector<float> vertexes = {0.75,  -0.75, 0.25,  -0.75, -0.25,
                                 -0.75, -0.75, -0.75, -0.75, -0.25,
                                 -0.75, 0.25,  -0.75, 0.75};
  std::vector<int> indexes = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7};
  EXPECT_EQ(vertexes, tmp.get_vertex_solution());
  EXPECT_EQ(indexes, tmp.get_index_solution());
}

TEST(Controller_maze, clear_solutions) {
  s21::Controller_maze tmp;
  tmp.open_file("./tests/4x4.maze");
  tmp.solve_maze(4, 4, 0, 0, 3, 3);
  tmp.clear_solution();
  std::vector<float> vertexes;
  std::vector<int> indexes;
  EXPECT_EQ(vertexes, tmp.get_vertex_solution());
  EXPECT_EQ(indexes, tmp.get_index_solution());
}

TEST(Controller_maze, rows_cols) {
  s21::Controller_maze tmp;
  tmp.open_file("./tests/4x4.maze");
  EXPECT_EQ(4, tmp.get_rows());
  EXPECT_EQ(4, tmp.get_cols());
}

TEST(Controller_cave, generate_cave) {
  s21::Controller_cave cave;
  cave.generate_cave(3, 4, 4, 4, 50);
  EXPECT_TRUE(cave.get_vertex().size() > 0);
  EXPECT_TRUE(cave.get_index().size() > 0);
}

TEST(Controller_cave, open_file) {
  s21::Controller_cave cave;
  cave.open_file(3, 4, "./tests/4x4.cave");
  std::vector<float> vertexes = {
      0,    1,    0,    0.5, 0.5, 0.5, 0.5, 1,    0,   0.5,  0,   0, 0.5, 0,
      0.5,  0.5,  0.5,  0.5, 0.5, 0,   1,   0,    1,   0.5,  -1,  0, -1,  -0.5,
      -0.5, -0.5, -0.5, 0,   0,   0,   0,   -0.5, 0.5, -0.5, 0.5, 0};
  std::vector<int> indexes = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,
                              10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
                              20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
                              30, 31, 32, 33, 34, 35, 36, 37, 38, 39};
  EXPECT_EQ(vertexes, cave.get_vertex());
  EXPECT_EQ(indexes, cave.get_index());
}

TEST(Controller_cave, rows_cols) {
  s21::Controller_cave cave;
  cave.open_file(3, 4, "./tests/4x4.cave");
  cave.set_birth(5);
  cave.set_death(5);
  EXPECT_EQ(4, cave.get_rows());
  EXPECT_EQ(4, cave.get_cols());
}

TEST(Controller_cave, celluar_automation) {
  s21::Controller_cave cave;
  cave.open_file(3, 4, "./tests/4x4.cave");
  cave.cellular_automation();
  std::vector<float> vertexes = {-0.5, 0.5, -0.5, 0,    0, 0,    0, 0.5,
                                 0.5,  0.5, 0.5,  0,    1, 0,    1, 0.5,
                                 0.5,  0,   0.5,  -0.5, 1, -0.5, 1, 0};
  std::vector<int> indexes = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11,
                              12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
  EXPECT_EQ(vertexes, cave.get_vertex());
  EXPECT_EQ(indexes, cave.get_index());
}

TEST(Controller, generate) {
  s21::Controller_maze tmp;
  tmp.generate_labirint(18, 18);
  ASSERT_EQ(1306, tmp.get_vertex_maze().size());
}

TEST(Maze, generate) {
  s21::Maze tmp(18, 18);
  ASSERT_EQ(0, tmp.get_horizontal_matrix().size());
  ASSERT_EQ(0, tmp.get_vertical_matrix().size());
  tmp.generate_maze();
  ASSERT_EQ(18 * 18, tmp.get_horizontal_matrix().size());
  ASSERT_EQ(18 * 18, tmp.get_vertical_matrix().size());
}

TEST(Maze, read_from_file) {
  s21::Maze tmp;
  tmp.read_from_file("./tests/18x18.maze");
  std::vector<char> horizontal = {
      '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0',
      '0', '0', '0', '0', '0', '1', '0', '1', '1', '0', '1', '0', '0', '0', '0',
      '1', '0', '0', '0', '0', '1', '0', '1', '1', '1', '1', '0', '0', '1', '0',
      '0', '1', '0', '0', '0', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0',
      '1', '0', '1', '1', '1', '0', '1', '0', '0', '1', '1', '0', '0', '1', '1',
      '1', '1', '0', '1', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1',
      '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0', '1', '1', '1', '0',
      '1', '0', '0', '0', '1', '1', '0', '0', '1', '0', '0', '1', '1', '0', '0',
      '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '0',
      '0', '0', '0', '1', '0', '0', '0', '1', '1', '0', '1', '0', '1', '1', '0',
      '1', '1', '0', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0', '0', '1',
      '1', '0', '0', '0', '0', '1', '0', '0', '1', '1', '0', '0', '0', '1', '0',
      '0', '1', '0', '0', '1', '1', '0', '0', '1', '0', '0', '0', '0', '1', '0',
      '0', '0', '0', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '0',
      '1', '1', '0', '0', '0', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1',
      '0', '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '0',
      '1', '0', '1', '1', '0', '1', '0', '0', '0', '0', '1', '0', '0', '1', '0',
      '1', '1', '0', '0', '1', '0', '0', '1', '1', '0', '0', '1', '0', '0', '0',
      '0', '1', '1', '0', '0', '0', '0', '1', '0', '1', '1', '0', '0', '0', '0',
      '0', '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '0', '1', '0', '1',
      '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '1'};
  std::vector<char> vertical = {
      '0', '1', '1', '0', '1', '0', '1', '1', '1', '0', '0', '1', '0', '0', '1',
      '1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '0', '1', '1', '1', '1',
      '0', '1', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '1',
      '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '0', '1', '0', '1',
      '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '0', '1', '1',
      '1', '1', '0', '1', '1', '0', '1', '0', '0', '1', '1', '1', '1', '0', '1',
      '1', '0', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1',
      '0', '0', '1', '0', '1', '0', '1', '0', '0', '1', '0', '0', '1', '1', '0',
      '1', '0', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0',
      '1', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '1',
      '0', '0', '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0',
      '1', '0', '0', '1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '1',
      '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '0',
      '1', '1', '1', '0', '1', '1', '1', '0', '0', '0', '0', '1', '1', '1', '0',
      '0', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1', '1', '0', '1',
      '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1',
      '0', '1', '0', '0', '0', '1', '1', '0', '0', '1', '1', '1', '0', '1', '1',
      '1', '0', '0', '1', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1',
      '0', '0', '1', '1', '1', '1', '1', '0', '1', '0', '0', '1', '1', '0', '1',
      '0', '1', '1', '1', '0', '0', '1', '0', '1', '0', '1', '0', '0', '1', '0',
      '1', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '1', '1',
      '0', '0', '0', '0', '0', '0', '0', '0', '1'};
  EXPECT_EQ(vertical, tmp.get_vertical_matrix());
  EXPECT_EQ(horizontal, tmp.get_horizontal_matrix());
}

TEST(Solution, read_from_file) {
  s21::Maze tmp;
  tmp.read_from_file("./tests/18x18.maze");
  s21::Solution sol(&tmp, 0, 0, 17, 17);
  std::vector<std::pair<int, int>> check = {
      {17, 17}, {17, 16}, {17, 15}, {17, 14}, {17, 13}, {17, 12}, {17, 11},
      {17, 10}, {16, 10}, {16, 9},  {16, 8},  {15, 8},  {14, 8},  {14, 9},
      {14, 10}, {13, 10}, {12, 10}, {11, 10}, {10, 10}, {9, 10},  {9, 9},
      {8, 9},   {7, 9},   {7, 8},   {8, 8},   {9, 8},   {9, 7},   {10, 7},
      {11, 7},  {11, 6},  {11, 5},  {11, 4},  {12, 4},  {13, 4},  {14, 4},
      {14, 5},  {15, 5},  {16, 5},  {16, 4},  {17, 4},  {17, 3},  {17, 2},
      {17, 1},  {17, 0},  {16, 0},  {15, 0},  {14, 0},  {14, 1},  {13, 1},
      {12, 1},  {12, 0},  {11, 0},  {10, 0},  {9, 0},   {8, 0},   {7, 0},
      {6, 0},   {5, 0},   {4, 0},   {3, 0},   {2, 0},   {1, 0},   {0, 0}};
  sol.start_program();
  EXPECT_EQ(check, sol.get_vector());
}

TEST(Solution, start_near_finish) {
  s21::Maze tmp;
  tmp.read_from_file("./tests/18x18.maze");
  s21::Solution sol(&tmp, 0, 0, 0, 1);
  std::vector<std::pair<int, int>> check = {{0, 1}, {0, 0}};
  sol.start_program();
  EXPECT_EQ(check, sol.get_vector());
}

TEST(Cave, generate) {
  s21::Cave cave(5, 4);
  cave.cave_generator(30, 30);
  EXPECT_EQ(30 * 30, cave.get_matrix().matrix.size());
}

TEST(Cave, without_timer) {
  s21::Cave cave(5, 4);
  cave.start_program("./tests/21x42.cave");
  std::vector<char> check = {
      '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0', '1',
      '1', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '1', '0', '0', '1',
      '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
      '1', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0', '1', '0', '0', '1',
      '1', '1', '0', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '0',
      '0', '1', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0',
      '1', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1',
      '0', '0', '0', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1',
      '1', '0', '1', '1', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1',
      '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1',
      '0', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '0',
      '1', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0', '0', '1', '1', '1',
      '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1',
      '1', '0', '1', '1', '1', '1', '0', '0', '1', '0', '0', '0', '1', '0', '1',
      '1', '1', '1', '0', '1', '0', '1', '1', '0', '1', '0', '1', '0', '1', '0',
      '0', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '0', '1', '1',
      '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1',
      '0', '1', '1', '1', '1', '1', '0', '0', '0', '1', '0', '1', '1', '1', '1',
      '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1',
      '0', '0', '0', '1', '1', '1', '0', '1', '0', '0', '1', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0',
      '0', '1', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1', '1', '0', '1',
      '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0',
      '1', '0', '0', '1', '1', '0', '1', '1', '0', '0', '1', '1', '1', '0', '0',
      '1', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1',
      '0', '0', '0', '0', '1', '1', '1', '0', '0', '1', '0', '1', '1', '0', '0',
      '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1',
      '1', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '1', '0',
      '1', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0',
      '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '1', '0', '1', '0', '1',
      '1', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '0', '1', '1',
      '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1',
      '1', '1', '0', '1', '0', '0', '1', '0', '0', '0', '0', '1', '1', '0', '1',
      '0', '0', '1', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '0',
      '0', '0', '1', '0', '0', '1', '0', '0', '1', '0', '1', '1', '1', '0', '0',
      '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0',
      '1', '1', '1', '0', '0', '0', '0', '1', '0', '0', '1', '0', '1', '1', '0',
      '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0',
      '1', '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '0', '0', '1',
      '0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '0', '0', '1', '1',
      '0', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1',
      '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '1', '0',
      '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '1', '1', '0', '0',
      '1', '0', '0', '1', '1', '1', '0', '0', '0', '0', '1', '0', '1', '0', '1',
      '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1',
      '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1',
      '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1',
      '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1',
      '1', '1', '0', '0', '1', '0', '1', '0', '0', '0', '1', '1', '1', '0', '1',
      '0', '0', '1', '1', '0', '0', '1', '1', '0', '1', '0', '1', '1', '1', '1',
      '0', '0', '1', '1', '1', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1',
      '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1', '1',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '1'};
  EXPECT_EQ(check, cave.get_matrix().matrix);
}

TEST(Cave, with_timer) {
  s21::Cave cave(5, 4);
  cave.start_program("./tests/21x42.cave");
  std::vector<char> check_1 = {
      '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '1', '0', '0', '1',
      '1', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '1', '0', '0', '1',
      '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1',
      '1', '0', '1', '0', '0', '1', '1', '0', '0', '0', '0', '1', '0', '0', '1',
      '1', '1', '0', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1', '0',
      '0', '1', '0', '0', '0', '1', '0', '0', '1', '0', '0', '0', '0', '0', '0',
      '1', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '0', '1',
      '0', '0', '0', '1', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '1',
      '1', '0', '1', '1', '1', '0', '1', '1', '0', '0', '1', '1', '1', '1', '1',
      '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1',
      '0', '1', '1', '1', '0', '0', '0', '0', '0', '1', '1', '0', '0', '1', '0',
      '1', '0', '0', '0', '1', '1', '1', '0', '1', '0', '0', '0', '1', '1', '1',
      '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1',
      '1', '0', '1', '1', '1', '1', '0', '0', '1', '0', '0', '0', '1', '0', '1',
      '1', '1', '1', '0', '1', '0', '1', '1', '0', '1', '0', '1', '0', '1', '0',
      '0', '0', '1', '1', '1', '0', '0', '0', '1', '1', '1', '1', '0', '1', '1',
      '0', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1',
      '0', '1', '1', '1', '1', '1', '0', '0', '0', '1', '0', '1', '1', '1', '1',
      '0', '0', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1',
      '0', '0', '0', '1', '1', '1', '0', '1', '0', '0', '1', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0',
      '0', '1', '0', '0', '1', '1', '0', '1', '1', '0', '1', '1', '1', '0', '1',
      '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '0',
      '1', '0', '0', '1', '1', '0', '1', '1', '0', '0', '1', '1', '1', '0', '0',
      '1', '1', '1', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1',
      '0', '0', '0', '0', '1', '1', '1', '0', '0', '1', '0', '1', '1', '0', '0',
      '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1',
      '1', '0', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '1', '1', '0', '1', '0',
      '1', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0',
      '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '1', '0', '1', '0', '1',
      '1', '0', '0', '1', '1', '1', '1', '0', '1', '0', '1', '1', '0', '1', '1',
      '1', '0', '1', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0', '1', '1',
      '1', '1', '0', '1', '0', '0', '1', '0', '0', '0', '0', '1', '1', '0', '1',
      '0', '0', '1', '0', '0', '1', '1', '1', '0', '0', '1', '1', '0', '1', '0',
      '0', '0', '1', '0', '0', '1', '0', '0', '1', '0', '1', '1', '1', '0', '0',
      '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '1', '1', '1', '0',
      '1', '1', '1', '0', '0', '0', '0', '1', '0', '0', '1', '0', '1', '1', '0',
      '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0',
      '1', '1', '0', '1', '1', '0', '0', '1', '1', '0', '1', '1', '0', '0', '1',
      '0', '0', '1', '0', '1', '0', '1', '1', '1', '1', '0', '0', '0', '1', '1',
      '0', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1',
      '0', '0', '1', '1', '0', '0', '0', '1', '1', '0', '1', '1', '1', '1', '0',
      '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '1', '1', '0', '0',
      '1', '0', '0', '1', '1', '1', '0', '0', '0', '0', '1', '0', '1', '0', '1',
      '1', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '1',
      '0', '0', '0', '0', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1',
      '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '1', '1',
      '0', '0', '1', '1', '1', '1', '1', '0', '1', '1', '0', '0', '0', '1', '1',
      '1', '1', '0', '0', '1', '0', '1', '0', '0', '0', '1', '1', '1', '0', '1',
      '0', '0', '1', '1', '0', '0', '1', '1', '0', '1', '0', '1', '1', '1', '1',
      '0', '0', '1', '1', '1', '0', '0', '1', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '0', '1', '1', '1', '0', '0', '1', '1', '1', '1', '1', '1',
      '0', '0', '0', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1', '1',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '1', '1'};
  EXPECT_EQ(check_1, cave.get_matrix().matrix);
  cave.timer(1);
  std::vector<char> check_2 = {
      '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1',
      '1', '1', '1', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1',
      '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1',
      '1', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
      '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '1'};
  EXPECT_EQ(check_2, cave.get_matrix().matrix);
}