#include "mainwindow.h"
#include "songs.h"
#include <QApplication>
#include <QtDebug>
#include <QtDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;




  //  songs newsongs(":/Doc/Doc/Genres.csv");
  //  virtualMemo memo(":/Doc/Doc/Genres.csv");
   // memo.fullPages();

/*

    ifstream file("D:\\Datos2\\Proyecto1_2023\\Datos-II-Proyecto-I\\Grafica\\Doc\\Genres.csv");
    string line,word;
    getline(file, line);
    qDebug()<<QString::fromStdString(line);
    stringstream s(line);
    vector<string> row;

    while(getline(s,word,',')){
        qDebug()<<QString::fromStdString(word);
        row.push_back(word);
    }

    qDebug()<<row.size();
    qDebug()<<QString::fromStdString(row[0]);
*/

    w.show();




    return a.exec();
}
