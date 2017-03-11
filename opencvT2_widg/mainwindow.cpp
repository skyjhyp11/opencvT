#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "ColorDetectController.h"


//using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_open_clicked()
{
    /*
    QString img_name = QFileDialog::getOpenFileName( this, tr("Open Image"), ".",
                                                     tr("Image Files(*.png *.jpg *.jpeg *.bmp)"));
    //toAscii()返回8位描述的string,为QByteArray,data()表示返回QByteArray的指针，QByteArray为字节指针
    Mat src = imread( img_name.toAscii().data() );
    cvtColor( src, src, CV_BGR2RGB );
    QImage img = QImage( (const unsigned char*)(src.data), src.cols, src.rows, QImage::Format_RGB888 );
   //  namedWindow( "Image_Show", WINDOW_AUTOSIZE );
   //  imshow( "Image_Show", src );
    ui->label->setPixmap( QPixmap::fromImage(img) );
    //  ui->label->resize( ui->label->pixmap()->size() );
    */

    QString img_name=QFileDialog::getOpenFileName
             (this,tr("Open Img"),".",tr("Image Filess(*.png *.jpg *.jpeg *.bmp)"));
    cv::Mat src1=cv::imread(img_name.toAscii().data());//.toAscii()//BGR

    ColorDetectController::getInstance()->setInputImage(src1);
    cv::Mat src;
    cv::cvtColor(src1,src,CV_BGR2RGB);
    QImage img=QImage((const unsigned char*)(src.data),src.cols,src.rows,src.step,QImage::Format_RGB888);
    ui->lbl_Image->setPixmap(QPixmap::fromImage(img));//

    //ui->lbl_Image->resize( ui->lbl_Image->pixmap()->size() );//根据图像调整label大小
    ui->lbl_Image->setScaledContents(true);   //根据label调整图像大小

}

void MainWindow::on_btn_close_clicked()
{
    close();
    ColorDetectController::getInstance()->destroy();
}

void MainWindow::on_btn_SelectCol_clicked()
{
    QColor color=QColorDialog::getColor(Qt::green,this);
    //lbl显示
    if(color.isValid())
    {
        ui->lbl_RGB->setText("R:   "+QString::number(color.red(),10)+"\n"+
                             "G:   "+QString::number(color.green(),10)+"\n"+
                             "B:   "+QString::number(color.blue(),10));//+color.green+color.blue;
        //Color单体模式
        ColorDetectController::getInstance()
                ->setTargetColor(color.red(),color.green(),color.blue());
    }

}

void MainWindow::on_btn_Process_clicked()
{
   // ui->lbl_RGB->setText("asss");

    ColorDetectController::getInstance()->setColorDistanceThreshold(
              ui->verSlider_Threshold->value());
    ColorDetectController::getInstance()->process();
    cv::Mat res=ColorDetectController::getInstance()->getLastResult();//返回单值图像：CV_8U
    if(!res.empty())
    {
        //ui->lbl_RGB->setText("123");//for test
        //cv::cvtColor(res,res,CV_BGR2RGB);
        QImage qimg=QImage((const unsigned char*)(res.data),res.cols,res.rows,res.step,QImage::Format_Indexed8);
        ui->lbl_ImageRes->setPixmap(QPixmap::fromImage(qimg));
        ui->lbl_ImageRes->setScaledContents(true);   //根据label调整图像大小

    }
}

void MainWindow::on_verSlider_Threshold_sliderPressed() //单击 改变slider的值
{
   //ui->lbl_RGB->setText("123");
   ui->lbl_distance->setText(QString::number( ui->verSlider_Threshold->value(),10));
}



void MainWindow::on_verSlider_Threshold_valueChanged(int value)//拉动 改变slider的值
{
     ui->lbl_distance->setText("Threshold:"+QString::number(value ,10));//ui->verSlider_Threshold->value()
}

