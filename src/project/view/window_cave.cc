#include "window_cave.h"

#include "ui_window_cave.h"

Window_cave::Window_cave(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Window_cave) {
  ui->setupUi(this);
  connect(this, &Window_cave::openFile, ui->OpenGLWidget,
          &GLWidget_cave::openFile);
  connect(this, &Window_cave::generateCave, ui->OpenGLWidget,
          &GLWidget_cave::generateCave);
  connect(this, &Window_cave::start, ui->OpenGLWidget, &GLWidget_cave::start);
  connect(this, &Window_cave::next, ui->OpenGLWidget, &GLWidget_cave::next);
  connect(this, &Window_cave::set_birth, ui->OpenGLWidget,
          &GLWidget_cave::set_birth);
  connect(this, &Window_cave::set_death, ui->OpenGLWidget,
          &GLWidget_cave::set_death);
}

Window_cave::~Window_cave() { delete ui; }

void Window_cave::on_open_file_clicked() {
  QString fileName =
      QFileDialog::getOpenFileName(this, "Выберете файл", QDir::homePath());
  if (fileName != "") {
    std::pair<int, int> rows_cols = emit openFile(
        ui->birth->value(), ui->death->value(), fileName.toStdString());
    ui->rows->setValue(rows_cols.first);
    ui->cols->setValue(rows_cols.second);
  }
}

void Window_cave::on_cave_generator_clicked() {
  emit generateCave(ui->birth->value(), ui->death->value(), ui->rows->value(),
                    ui->cols->value(), ui->chance->value());
}

void Window_cave::on_start_clicked() {
  while (emit next() && !event_close) {
    QTime dieTime = QTime::currentTime().addMSecs(ui->milliseconds->value());
    while (QTime::currentTime() < dieTime) {
      QCoreApplication::processEvents(QEventLoop::AllEvents);
    }
  }
}

void Window_cave::on_next_clicked() { emit next(); }

void Window_cave::closeEvent(QCloseEvent *event) {
  event_close = true;
  close();
}

void Window_cave::on_birth_valueChanged(int arg1) { emit set_birth(arg1); }

void Window_cave::on_death_valueChanged(int arg1) { emit set_death(arg1); }
