#ifndef PAGE_CONTROLER_H
#define PAGE_CONTROLER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QListWidget>
#include <QScrollBar>
#include <string>
#include "songs.h"
using namespace std;
class Page_Controler : public QObject
{
    Q_OBJECT
public:
    explicit Page_Controler(QObject *parent = nullptr);

    void setPage(QListWidget*);
    void setFile(string);
    void fullPage();
    void setVB(QScrollBar*);



signals:


public slots:
    void getScrollPos(const int &value);


private:
    QListWidget *list;
    string file;
    songs *Songs;
    QScrollBar *VB;
    void Next();
    void Prev();

};

#endif // PAGE_CONTROLER_H
