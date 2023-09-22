#include "songs.h"


songs::songs(string FileName,QObject *parent){
    this->Memo = new virtualMemo(FileName);
    this->Memo->fullPages();
}



void songs::passAgetPrev(){
    this->Memo->getprevPage();

}


void songs::pruve(){
    this->Memo->movePage(1);

}
void songs::passAgetNext(){
    this->Memo->getnextPage();
}


vector<Album>* songs::getPrev(){
    return this->Memo->returnNext();
}

vector<Album>* songs::getCurr(){
    return this->Memo->returnCurr();
}

vector<Album>* songs::getNext(){
    return this->Memo->returnNext();
}
