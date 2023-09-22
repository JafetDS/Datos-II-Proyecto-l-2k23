

#include <QObject>
#include "virtualMemo.h"


#ifndef SONGS_H
#define SONGS_H



class songs{
    public:

        songs(string,QObject*);

        virtualMemo *Memo;

        vector<Album>* getNext();
        vector<Album>* getCurr();
        vector<Album>* getPrev();
        void passAgetNext();
        void passAgetPrev();
        void pruve();

        
    private:






};





#endif
