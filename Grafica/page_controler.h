
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QObject>
#include <QListWidget>
#include <QScrollBar>
#include <string>
#include "songs.h"
#ifndef PAGE_CONTROLER_H
#define PAGE_CONTROLER_H


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
    void setPageMemo();

    vector<Album> *prev;
    vector<Album> *curr;
    vector<Album> *next;

    void fullPages();
    void getnextPage();
    void getprevPage();
    void movePage(int);
    vector<Album>* returnNext();
    vector<Album>* returnCurr();
    vector<Album>* returnPrev();



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

    string File;

    vector<vector<Album> > Memo = {{},{},{}};

    vector<Album> *prevPage;
    vector<Album> *currPage;
    vector<Album> *nextPage;

    int prevPageIndx;
    int currPageIndx;
    int nextPageIndx;

    streamoff *docCIndx;
    vector<streamoff> pageRecord;



    void setPagepoint();
    void loadNewPage(ifstream*,vector<Album>*);




};

#endif // PAGE_CONTROLER_H
