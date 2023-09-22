
#include "virtualMemo.h"




#ifndef SONGS_H
#define SONGS_H



class songs{
    public:

        songs(string,QListWidget*);

        virtualMemo *Memo;

        vector<Album> getNext();
        vector<Album> getCurr();
        vector<Album> getPrev();
        void passAgetNext();
        void passAgetPrev();


        
    private:






};





#endif
