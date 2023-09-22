#include "page_controler.h"
#include <QtDebug>
Page_Controler::Page_Controler(QObject *parent) : QObject(parent)
{

}

void Page_Controler::setVB(QScrollBar *vb){
    this->VB = vb;

}

void Page_Controler::setPage(QListWidget *list){
    this->list = list;
}

void Page_Controler::setFile(string file){
     this->file = file;
     songs newsongs(this->file,this->list);
     this->Songs = &newsongs;

}




void Page_Controler::getScrollPos(const int &value){
    if(this->VB->maximum()==value){
        //this->list->clear();
        this->Next();
    }
   // qDebug()<<value;

}

void Page_Controler::Next(){
    this->list->clear();
    this->Songs->passAgetNext();


   // vector<Album> next = this->Songs->passAgetNext();
   // vector<Album> prev = this->Songs->getPrev();
    for(int k = 0; k < 100; k++){
        this->list->addItem(QString::fromStdString("a")+"_"+QString::fromStdString("b"));

    }


   /* vector<Album> vacio = {};
    if(next.size()!=0){
       // this->list->clear();
        for(int k = 0; k < next.size(); k++){
            this->list->addItem(QString::fromStdString(next[k].id)+"_"+QString::fromStdString(next[k].name));

        }

    }*/

}

void Page_Controler::Prev(){


}






void Page_Controler::fullPage(){
    vector<Album> prev = this->Songs->getPrev();
    vector<Album> curr = this->Songs->getCurr();
    vector<Album> next = this->Songs->getNext();


    for(int i = 0; i < prev.size(); i++){
        this->list->addItem(QString::fromStdString(prev[i].id)+"_"+QString::fromStdString(prev[i].name));

    }

    for(int j = 0; j < curr.size(); j++){
        this->list->addItem(QString::fromStdString(curr[j].id)+"_"+QString::fromStdString(curr[j].name));

    }


    for(int k = 0; k < next.size(); k++){
        this->list->addItem(QString::fromStdString(next[k].id)+"_"+QString::fromStdString(next[k].name));

    }





}
