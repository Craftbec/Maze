/// \file
#include "solution.h"

namespace s21 {
Solution::Solution(Maze *maze, int start_i, int start_j, int end_i, int end_j)
    : maze_(maze) {
  start.first = start_i;
  start.second = start_j;
  end.first = end_i;
  end.second = end_j;
}

void Solution::start_program() { make_path_in_vector(fill_path()); }

std::vector<std::pair<int, int>> Solution::get_vector() { return solution_; }

int Solution::up(std::pair<int, int> index) {
  return (index.first - 1) * maze_->get_cols() + index.second;
}

int Solution::down(std::pair<int, int> index) {
  return (index.first + 1) * maze_->get_cols() + index.second;
}

int Solution::left(std::pair<int, int> index) {
  return index.first * maze_->get_cols() + index.second - 1;
}

int Solution::right(std::pair<int, int> index) {
  return index.first * maze_->get_cols() + index.second + 1;
}

std::pair<int, int> Solution::index_to_pair(int idx) {
  std::pair<int, int> index;
  index.first = idx / maze_->get_cols();
  index.second = idx % maze_->get_cols();
  return index;
}

int Solution::pair_to_index(int i, int j) { return i * maze_->get_cols() + j; }

std::vector<int> Solution::fill_path() {
  std::vector<int> out(maze_->get_rows() * maze_->get_cols());
  int next = 0;
  int flag = 1;
  int start_ = pair_to_index(start.first, start.second);
  int stop_ = pair_to_index(end.first, end.second);
  std::queue<int> wave;
  wave.push(start_);
  while (flag) {
    next++;
    int end = wave.size();
    for (int i = 0; i < end; i++) {
      if (index_to_pair(wave.front()).first) {
        int idx = up(index_to_pair(wave.front()));
        if (maze_->get_horizontal_matrix()[wave.front() - maze_->get_cols()] ==
            '0') {
          if (out[idx] == 0 && idx != start_) {
            wave.push(idx);
            out[idx] = next;
          }
          if (idx == stop_) flag = 0;
        }
      }
      if (index_to_pair(wave.front()).first < maze_->get_rows() - 1) {
        int idx = down(index_to_pair(wave.front()));
        if (maze_->get_horizontal_matrix()[wave.front()] == '0') {
          if (out[idx] == 0 && idx != start_) {
            wave.push(idx);
            out[idx] = next;
          }
          if (idx == stop_) flag = 0;
        }
      }
      if (index_to_pair(wave.front()).second) {
        int idx = left(index_to_pair(wave.front()));
        if (maze_->get_vertical_matrix()[wave.front() - 1] == '0') {
          if (out[idx] == 0 && idx != start_) {
            wave.push(idx);
            out[idx] = next;
          }
          if (idx == stop_) flag = 0;
        }
      }
      if (index_to_pair(wave.front()).second < maze_->get_cols() - 1) {
        int idx = right(index_to_pair(wave.front()));
        if (maze_->get_vertical_matrix()[wave.front()] == '0') {
          if (out[idx] == 0 && idx != start_) {
            wave.push(idx);
            out[idx] = next;
          }
          if (idx == stop_) flag = 0;
        }
      }

      wave.pop();
    }
  }
  return out;
}

void Solution::make_path_in_vector(std::vector<int> matrix) {
  std::pair<int, int> tmp_end = end;
  int last = matrix[pair_to_index(tmp_end.first, tmp_end.second)];
  solution_.push_back(tmp_end);
  if (last == 1) {
    solution_.push_back(start);
    last = 0;
  }
  while (last) {
    if (tmp_end.first && matrix[up(tmp_end)] == last - 1 &&
        maze_->get_horizontal_matrix()[up(tmp_end)] == '0') {
      tmp_end = index_to_pair(up(tmp_end));
      solution_.push_back(tmp_end);
      last--;
      continue;
    }
    if (tmp_end.first < maze_->get_rows() - 1 &&
        matrix[down(tmp_end)] == last - 1 &&
        maze_->get_horizontal_matrix()[pair_to_index(tmp_end.first,
                                                     tmp_end.second)] == '0') {
      tmp_end = index_to_pair(down(tmp_end));
      solution_.push_back(tmp_end);
      last--;
      continue;
    }
    if (tmp_end.second && matrix[left(tmp_end)] == last - 1 &&
        maze_->get_vertical_matrix()[left(tmp_end)] == '0') {
      tmp_end = index_to_pair(left(tmp_end));
      solution_.push_back(tmp_end);
      last--;
      continue;
    }
    if (tmp_end.second < maze_->get_cols() - 1 &&
        matrix[right(tmp_end)] == last - 1 &&
        maze_->get_vertical_matrix()[pair_to_index(tmp_end.first,
                                                   tmp_end.second)] == '0') {
      tmp_end = index_to_pair(right(tmp_end));
      solution_.push_back(tmp_end);
      last--;
      continue;
    }
  }
}
}  // namespace s21
