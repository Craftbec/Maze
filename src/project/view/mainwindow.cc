#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(this, &MainWindow::openFile, ui->openGLWidget,
          &GLWidget_maze::openFile);
  connect(this, &MainWindow::maze_generate, ui->openGLWidget,
          &GLWidget_maze::maze_generate);
}

MainWindow::~MainWindow() {
  close();
  delete ui;
}

void MainWindow::on_open_file_clicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, "Выберете файл", QDir::homePath());
  if (fileName != "") {
    std::pair<int, int> rows_cols = emit openFile(fileName.toStdString());
    ui->rows->setValue(rows_cols.first);
    ui->cols->setValue(rows_cols.second);
  }
}

void MainWindow::on_maze_generator_clicked() {
  emit maze_generate(ui->rows->value(), ui->cols->value());
}

void MainWindow::on_pushButton_clicked() { window_cave.show(); }
