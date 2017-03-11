#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_open_clicked();

    void on_btn_close_clicked();
    
    void on_btn_SelectCol_clicked();

    void on_btn_Process_clicked();

    void on_verSlider_Threshold_sliderPressed();

    void on_verSlider_Threshold_valueChanged(int value);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
