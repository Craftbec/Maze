/// \file
#include "maze.h"

namespace s21 {
Maze::Maze(int rows_, int cols_) {
  matr_.rows = rows_;
  matr_.cols = cols_;
  counter_ = 1;
}

std::string Maze::name_generate() {
  return "./project/files/" + std::to_string(matr_.rows) + "x" +
         std::to_string(matr_.cols) + ".maze";
}

void Maze::fill_empty_value() {
  for (int i = 0; i < matr_.cols; i++) {
    sideLine_.push_back(0);
  }
}

void Maze::unique_value() {
  for (int i = 0; i < matr_.cols; i++) {
    if (sideLine_[i] == 0) {
      sideLine_[i] = counter_;
      counter_++;
    }
  }
}

bool Maze::random_bool() {
  bool flag = 1;
  int b = 0;

  std::thread th_flag([&]() {
    while (flag) b++;
  });
  std::this_thread::sleep_for(std::chrono::microseconds(10));
  flag = 0;
  th_flag.join();
  return b % 2;
}

void Maze::right_borders() {
  for (int i = 0; i < matr_.cols - 1; i++) {
    bool choise = random_bool();
    if (choise == true || sideLine_[i] == sideLine_[i + 1]) {
      matr_.vertical_wall.push_back('1');
    } else {
      union_of_sets(i, sideLine_[i]);
      matr_.vertical_wall.push_back('0');
    }
  }
  matr_.vertical_wall.push_back('1');
}

void Maze::union_of_sets(int i, int el) {
  int next_el = sideLine_[i + 1];
  for (int j = 0; j < matr_.cols; j++) {
    if (sideLine_[j] == next_el) {
      sideLine_[j] = el;
    }
  }
}

void Maze::bottom_line() {
  for (int i = 0; i < matr_.cols; i++) {
    bool choise = random_bool();
    if (choise == true && number_of_cells(sideLine_[i]) != 1) {
      matr_.horizontal_wall.push_back('1');
    } else {
      matr_.horizontal_wall.push_back('0');
    }
  }
}

int Maze::number_of_cells(int num) {
  int counter = 0;
  for (int i = 0; i < matr_.cols; i++) {
    if (num == sideLine_[i]) counter++;
  }
  return counter;
}

void Maze::adding_endLine() {
  unique_value();
  right_borders();
  check_end();
}

void Maze::check_end() {
  for (int i = 0; i < matr_.cols; i++) {
    int tmp = (matr_.rows - 1) * matr_.cols + i;
    if (sideLine_[i] != sideLine_[i + 1]) {
      if (tmp < (int)matr_.vertical_wall.size() - 1) {
        matr_.vertical_wall[tmp] = '0';
        union_of_sets(i, sideLine_[i]);
      }
    }
    matr_.horizontal_wall.push_back('1');
  }
  matr_.horizontal_wall[matr_.horizontal_wall.size() - 1] = '1';
}

void Maze::wall_check(int row) {
  for (int i = 0; i < matr_.cols; i++) {
    int tmp = row * matr_.cols + i;
    if (count_wall(sideLine_[i], row) == 0) {
      matr_.horizontal_wall[tmp] = '0';
    }
  }
}

int Maze::count_wall(int element, int row) {
  int count = 0;
  int tmp1 = 0;
  for (int i = 0; i < matr_.cols; i++) {
    int tmp = row * matr_.cols + i;
    if (sideLine_[i] == element && matr_.horizontal_wall[tmp] == '0') {
      count++;
    }
    if (sideLine_[i] == element) tmp1++;
  }
  return count;
}

void Maze::wall_removal(int row) {
  for (int i = 0; i < matr_.cols; i++) {
    int tmp = row * matr_.cols + i;
    if (matr_.horizontal_wall[tmp] == '1') {
      sideLine_[i] = 0;
    }
  }
}

void Maze::writing_to_file(std::string path_to_file) {
  std::ofstream ofs(path_to_file);
  if (ofs.is_open()) {
    ofs << matr_.rows << " " << matr_.cols << std::endl;
    for (int i = 0; i < matr_.rows; i++) {
      ofs << matr_.vertical_wall[i * matr_.cols];
      for (int j = 1; j < matr_.cols; j++) {
        ofs << " " << matr_.vertical_wall[i * matr_.cols + j];
      }
      ofs << "\n";
    }
    ofs << "\n";
    for (int i = 0; i < matr_.rows; i++) {
      ofs << matr_.horizontal_wall[i * matr_.cols];
      for (int j = 1; j < matr_.cols; j++) {
        ofs << " " << matr_.horizontal_wall[i * matr_.cols + j];
      }
      if (i != matr_.rows - 1) ofs << "\n";
    }
    ofs.close();
  }
}

void Maze::read_from_file(std::string path_to_file) {
  std::fstream fs;
  fs.open(path_to_file, std::fstream::in);
  int z = 0;
  while (!fs.eof()) {
    std::string str;
    fs >> str;
    if (z == 0) {
      matr_.rows = std::stoi(str);
    } else if (z == 1) {
      matr_.cols = std::stoi(str);
    } else if (z > 1 && z < matr_.rows * matr_.cols + 2) {
      matr_.vertical_wall.push_back(str[0]);
    } else {
      matr_.horizontal_wall.push_back(str[0]);
    }
    z++;
  }
  fs.close();
}

void Maze::generate_maze() {
  fill_empty_value();
  for (int j = 0; j < matr_.rows - 1; j++) {
    unique_value();
    right_borders();
    bottom_line();
    wall_check(j);
    wall_removal(j);
  }

  adding_endLine();
  writing_to_file(name_generate());
}

int Maze::get_rows() { return matr_.rows; }
int Maze::get_cols() { return matr_.cols; }
std::vector<char> Maze::get_vertical_matrix() { return matr_.vertical_wall; }
std::vector<char> Maze::get_horizontal_matrix() {
  return matr_.horizontal_wall;
}
Matrix_maze Maze::get_matrix() { return matr_; }
}  // namespace s21
