#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <cmath>
#include "Album.cpp"
#include <QListWidget>

using namespace std;

#ifndef VIRTUAL_MEMO_H
#define VIRTUAL_MEMO_H

class virtualMemo{

    public:

        virtualMemo(string);
        void fullPages();
        void getnextPage();
        void getprevPage();
        void movePage(int);
        vector<Album>* returnNext();
        vector<Album>* returnCurr();
        vector<Album>* returnPrev();

    private:
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





#endif
