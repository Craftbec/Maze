#ifndef WINDOW_CAVE_H
#define WINDOW_CAVE_H
#include <QFileDialog>
#include <QMainWindow>

namespace Ui {
class Window_cave;
}

class Window_cave : public QMainWindow {
  Q_OBJECT

 public:
  explicit Window_cave(QWidget *parent = nullptr);
  ~Window_cave();

 private slots:
  void on_open_file_clicked();
  void on_cave_generator_clicked();
  void on_start_clicked();
  void on_next_clicked();
  void closeEvent(QCloseEvent *event) override;
  void on_birth_valueChanged(int arg1);
  void on_death_valueChanged(int arg1);

 private:
  Ui::Window_cave *ui;
  bool event_close = false;

 signals:
  std::pair<int, int> openFile(int birth, int death, std::string filename);
  void generateCave(int birth, int death, int rows, int cols, int chance);
  void start(int milliseconds);
  bool next();
  void set_death(int value);
  void set_birth(int value);
};

#endif  // WINDOW_CAVE_H
