#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <iostream>
#include <QFileDialog>
#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QSlider>
#include <algorithm>
#include <numeric>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int meanA_x = 0;
    int meanA_y = 0;
    int meanB_x = 0;
    int meanB_y = 0;

private slots:
    void on_loadImageButton_clicked();
    void on_loadImageButton2_clicked();
    void on_saveImageButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void Slot_Mouse_Pressed();
    void Slot_Mouse_Current_Position();
    void Slot_Mouse_Current_Position2();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
