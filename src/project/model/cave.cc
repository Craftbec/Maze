/// \file
#include "cave.h"

namespace s21 {
Cave::Cave(int birth, int death, int chance) {
  birth_ = birth;
  death_ = death;
  chance_ = chance;
}

void Cave::start_program(std::string path_to_file) {
  std::string line;
  std::ifstream in(path_to_file);
  int count = -1;
  if (in.is_open()) {
    while (getline(in, line)) {
      if (count == -1) {
        set_rows_cols(line);
        count++;
      } else {
        set_matrix(line);
      }
    }
  }
  in.close();
}

bool Cave::random_bool() {
  bool flag = 1;
  int b = 0;
  std::thread th_flag([&]() {
    while (flag) b++;
  });
  std::this_thread::sleep_for(std::chrono::microseconds(10));
  flag = 0;
  th_flag.join();
  if (chance_ == 0) chance_ = -1;
  return chance_ >= b % 101;
}

void Cave::cave_generator(int rows, int cols) {
  std::string path_to_file = "./project/files/" + std::to_string(rows) + "x" +
                             std::to_string(cols) + ".cave";
  std::ofstream ofs(path_to_file);
  if (ofs.is_open()) {
    ofs << rows << " " << cols << std::endl;
    for (int i = 0; i < rows; i++) {
      ofs << random_bool();
      for (int j = 1; j < cols; j++) {
        ofs << " " << random_bool();
      }
      if (i < rows - 1) ofs << std::endl;
    }
    ofs.close();
    start_program(path_to_file);
  }
}

void Cave::set_rows_cols(std::string line) {
  int i = 0;
  std::string tmp;
  while (line[i]) {
    if (line[i] != ' ') {
      tmp.push_back(line[i]);
    } else {
      cave_.rows = atoi(&tmp[0]);
      tmp.clear();
    }
    i++;
  }
  cave_.cols = atoi(&tmp[0]);
}

void Cave::set_matrix(std::string str) {
  int i = 0;
  while (str[i]) {
    if (str[i] == '0') cave_.matrix.push_back('0');

    if (str[i] == '1') cave_.matrix.push_back('1');
    i++;
  }
}

bool Cave::cellular_automation() {
  bool flag = 1;
  std::vector<char> tmp;
  for (int i = 0; i < (int)cave_.matrix.size(); i++) {
    if (cave_.matrix[i] == '1') {
      if (living_cells(i) < death_) {
        tmp.push_back('0');
      } else {
        tmp.push_back('1');
      }
    } else {
      if (living_cells(i) > birth_) {
        tmp.push_back('1');
      } else {
        tmp.push_back('0');
      }
    }
  }
  if (cave_.matrix == tmp) flag = 0;
  cave_.matrix = tmp;
  return flag;
}

int Cave::living_cells(int i) {
  int res = 0;
  int i_tmp1 = i / cave_.rows;
  int j_tmp1 = i % cave_.cols;
  for (int a = i_tmp1 - 1; a <= i_tmp1 + 1; a++) {
    for (int b = j_tmp1 - 1; b <= j_tmp1 + 1; b++) {
      if (a != i_tmp1 || b != j_tmp1) {
        int tmp_i = a;
        int tmp_j = b;

        if (tmp_i == -1) tmp_i = (cave_.rows - 1);
        if (tmp_i >= cave_.rows) tmp_i = 0;
        if (tmp_j == -1) tmp_j = (cave_.cols - 1);
        if (tmp_j >= cave_.cols) tmp_j = 0;
        int index = tmp_i * cave_.cols + tmp_j;
        if (cave_.matrix[index] == '1') res++;
      }
    }
  }
  return res;
}

void Cave::timer(int N) {
  do {
    std::this_thread::sleep_for(std::chrono::milliseconds(N));
  } while (cellular_automation());
}

Matrix_cave Cave::get_matrix() { return cave_; }
}  // namespace s21
