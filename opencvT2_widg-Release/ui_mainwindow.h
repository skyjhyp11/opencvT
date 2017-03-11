/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_open;
    QPushButton *btn_close;
    QLabel *lbl_Image;
    QPushButton *btn_SelectCol;
    QPushButton *btn_Process;
    QSlider *verSlider_Threshold;
    QLabel *lbl_distance;
    QLabel *lbl_RGB;
    QLabel *lbl_ImageRes;
    QMenuBar *menuBar;
    QMenu *menuShow_Image;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(701, 613);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_open = new QPushButton(centralWidget);
        btn_open->setObjectName(QString::fromUtf8("btn_open"));
        btn_open->setGeometry(QRect(10, 10, 100, 30));
        btn_open->setMaximumSize(QSize(500, 500));
        btn_close = new QPushButton(centralWidget);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setGeometry(QRect(10, 500, 100, 30));
        btn_close->setMaximumSize(QSize(500, 500));
        lbl_Image = new QLabel(centralWidget);
        lbl_Image->setObjectName(QString::fromUtf8("lbl_Image"));
        lbl_Image->setGeometry(QRect(170, 10, 421, 261));
        lbl_Image->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 218, 164);"));
        lbl_Image->setOpenExternalLinks(false);
        btn_SelectCol = new QPushButton(centralWidget);
        btn_SelectCol->setObjectName(QString::fromUtf8("btn_SelectCol"));
        btn_SelectCol->setGeometry(QRect(10, 40, 100, 30));
        btn_Process = new QPushButton(centralWidget);
        btn_Process->setObjectName(QString::fromUtf8("btn_Process"));
        btn_Process->setEnabled(true);
        btn_Process->setGeometry(QRect(10, 460, 100, 30));
        verSlider_Threshold = new QSlider(centralWidget);
        verSlider_Threshold->setObjectName(QString::fromUtf8("verSlider_Threshold"));
        verSlider_Threshold->setGeometry(QRect(40, 150, 41, 211));
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        verSlider_Threshold->setFont(font);
        verSlider_Threshold->setMouseTracking(true);
        verSlider_Threshold->setContextMenuPolicy(Qt::PreventContextMenu);
        verSlider_Threshold->setAcceptDrops(true);
        verSlider_Threshold->setMaximum(255);
        verSlider_Threshold->setOrientation(Qt::Vertical);
        lbl_distance = new QLabel(centralWidget);
        lbl_distance->setObjectName(QString::fromUtf8("lbl_distance"));
        lbl_distance->setGeometry(QRect(20, 370, 111, 51));
        lbl_distance->setTextFormat(Qt::AutoText);
        lbl_distance->setWordWrap(false);
        lbl_distance->setOpenExternalLinks(false);
        lbl_RGB = new QLabel(centralWidget);
        lbl_RGB->setObjectName(QString::fromUtf8("lbl_RGB"));
        lbl_RGB->setGeometry(QRect(20, 70, 81, 81));
        lbl_ImageRes = new QLabel(centralWidget);
        lbl_ImageRes->setObjectName(QString::fromUtf8("lbl_ImageRes"));
        lbl_ImageRes->setGeometry(QRect(170, 280, 421, 261));
        lbl_ImageRes->setStyleSheet(QString::fromUtf8("background-color: rgb(221, 218, 164);"));
        lbl_ImageRes->setOpenExternalLinks(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 701, 31));
        menuShow_Image = new QMenu(menuBar);
        menuShow_Image->setObjectName(QString::fromUtf8("menuShow_Image"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuShow_Image->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "ColorDetectorUI", 0, QApplication::UnicodeUTF8));
        btn_open->setText(QApplication::translate("MainWindow", "Open Image", 0, QApplication::UnicodeUTF8));
        btn_close->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        lbl_Image->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">show Image</p></body></html>", 0, QApplication::UnicodeUTF8));
        btn_SelectCol->setText(QApplication::translate("MainWindow", "Select Color", 0, QApplication::UnicodeUTF8));
        btn_Process->setText(QApplication::translate("MainWindow", "Process", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        verSlider_Threshold->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        lbl_distance->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Threshold: 000</p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_RGB->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">RGB</p></body></html>", 0, QApplication::UnicodeUTF8));
        lbl_ImageRes->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">show Image</p></body></html>", 0, QApplication::UnicodeUTF8));
        menuShow_Image->setTitle(QApplication::translate("MainWindow", "show Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
