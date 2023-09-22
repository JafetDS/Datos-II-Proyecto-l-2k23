#include "songs.h"


songs::songs(string FileName,QListWidget* list){
    this->Memo = new virtualMemo(FileName);
    this->Memo->list = list;
    this->Memo->fullPages();
}



void songs::passAgetPrev(){
    this->Memo->getprevPage();

    Memo->setUI();



  //  return this->Memo->returnPrev();

}
void songs::passAgetNext(){
    this->Memo->getnextPage();

    Memo->setUI();



  //  return this->Memo->returnNext();
}


vector<Album> songs::getPrev(){
    return this->Memo->returnNext();
}

vector<Album> songs::getCurr(){
    return this->Memo->returnCurr();
}

vector<Album> songs::getNext(){
    return this->Memo->returnNext();
}
