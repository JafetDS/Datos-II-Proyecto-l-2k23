#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QScrollBar>
#include "page_controler.h"
#include <QtDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);



    Page_Controler *controlerP = new Page_Controler();



    controlerP->setPage(ui->listWidget);
    QScrollBar *vb = ui->listWidget->verticalScrollBar();
    controlerP->setFile("D:\\Datos2\\Proyecto1_2023\\Datos-II-Proyecto-I-2k23\\Grafica\\Doc\\Genres.csv");
    controlerP->fullPage();
    controlerP->setVB(vb);

    connect(vb,SIGNAL(valueChanged(int)),controlerP,SLOT(getScrollPos(int)));

   // int oldValue = vb->value();
  //  qDebug<<oldValue;

    //int oldValue = vb->value();
    //doSomething()
    //vb->setValue(oldValue);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
}

