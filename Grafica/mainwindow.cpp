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



    Page_Controler *controlerP = new Page_Controler(this);



    controlerP->setPage(ui->listWidget);
    QScrollBar *vb = ui->listWidget->verticalScrollBar();
    controlerP->setFile("D:\\Datos2\\Proyecto1_2023\\Datos-II-Proyecto-I-2k23\\Grafica\\Doc\\Genres.csv");
    controlerP->setVB(vb);
    controlerP->setPageMemo();
    controlerP->fullPage();
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
    ifstream file("D:\\Datos2\\Proyecto1_2023\\Datos-II-Proyecto-I-2k23\\Grafica\\Doc\\Genres.csv");
    string line,word;
    streamoff initialPos = file.tellg();

    file.seekg(initialPos);
    while(file.tellg()!=EOF){
        getline(file, line);
       // cout<<file->tellg()<<endl;
        stringstream s(line);
        vector<string> row;

        while(getline(s,word,',')){
            row.push_back(word);
        }
        Album album;
        album.id = row[0];
        album.name = row[3];
        ui->listWidget->addItem(QString::fromStdString(album.id)+"_"+QString::fromStdString(album.name));
    }


}

