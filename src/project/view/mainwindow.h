#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QFileDialog>
#include <QMainWindow>

#include "window_cave.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_open_file_clicked();
  void on_maze_generator_clicked();
  void on_pushButton_clicked();

 signals:
  std::pair<int, int> openFile(std::string);
  void maze_generate(int rows, int cols);

 private:
  Ui::MainWindow *ui;
  Window_cave window_cave;
};
#endif  // MAINWINDOW_H
