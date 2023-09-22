#include "page_controler.h"
#include <QtDebug>
Page_Controler::Page_Controler(QObject *parent) : QObject(parent)
{

    this->prevPageIndx = 0;
    this->currPageIndx = 1;
    this->nextPageIndx = 2;
    streamoff n = 0;
    this->pageRecord.push_back(n);
}

void Page_Controler::setVB(QScrollBar *vb){
    this->VB = vb;

}

void Page_Controler::setPage(QListWidget *list){
    this->list = list;
}

void Page_Controler::setFile(string file){

     this->File = file;

     this->fullPages();
    /*
     this->file = file;
     songs newsongs(this->file,this->parent());
     this->Songs = &newsongs;
*/
}




void Page_Controler::getScrollPos(const int &value){
    if(this->VB->maximum()==value){

        this->Next();

    }else if(this->VB->minimum()==value){

        this->Prev();
    }




}

void Page_Controler::Next(){
    this->list->clear();
    this->getnextPage();
    this->setPageMemo();
    this->fullPage();

}

void Page_Controler::Prev(){
    this->list->clear();
    this->getprevPage();
    this->setPageMemo();
    this->fullPage();

}




void Page_Controler::fullPage(){
    for(int i = 0; i < prev->size(); i++){
        this->list->addItem(QString::fromStdString(prev->at(i).id)+"_"+QString::fromStdString(prev->at(i).name));
    }
    for(int j = 0; j < curr->size(); j++){
        this->list->addItem(QString::fromStdString(curr->at(j).id)+"_"+QString::fromStdString(curr->at(j).name));
    }
    for(int k = 0; k < next->size(); k++){
        this->list->addItem(QString::fromStdString(next->at(k).id)+"_"+QString::fromStdString(next->at(k).name));

    }
}


void Page_Controler::setPageMemo(){
    prev = this->prevPage;
    curr = this->currPage;
    next = this->nextPage;
}
//_______________________________________________________________________________________________

void Page_Controler::fullPages(){
  //  cout<<this->pageRecord[0]<<endl;
    ifstream file(this->File);
    string line,word;
    getline(file, line);
    streamoff initialPos = file.tellg();
    vector<Album> *Page;
    file.seekg(initialPos);


    for(int i = 0; i<3 ; i++){

        this->pageRecord.push_back(file.tellg());
        Page = &this->Memo[i];
        loadNewPage(&file,Page);
    }


 //   cout<<file.tellg()<<endl;


    this->pageRecord.push_back(file.tellg());

    this->docCIndx = &(this->pageRecord[2]);
    setPagepoint();
    file.close();
}

void Page_Controler::loadNewPage(ifstream* file,vector<Album>* Page){
    string line,word;
    Page->clear();
  //  cout<<file->tellg()<<endl;
    for(int j= 0; j < 27; j++){
        getline(*file, line);
       // cout<<file->tellg()<<endl;
        stringstream s(line);
        vector<string> row;

        while(getline(s,word,',')){
            row.push_back(word);
        }
        Album album;
        album.id = row[0];
        album.name = row[3];
        Page->push_back(album);
    }
}

void Page_Controler::setPagepoint(){
    this->prevPage = &this->Memo[this->prevPageIndx];
    this->currPage = &this->Memo[this->currPageIndx];
    this->nextPage = &this->Memo[this->nextPageIndx];
}





void Page_Controler::getnextPage(){
    if(*(this->docCIndx+2)>-1){this->movePage(1);}
    return;

}

void Page_Controler::getprevPage(){
    if(*(this->docCIndx-2)!=0){this->movePage(-1);}
    return;


}


void Page_Controler::movePage(int n){

    this->prevPageIndx = abs((this->prevPageIndx+(1*n))%3);
    this->currPageIndx = abs((this->currPageIndx+(1*n))%3);
    this->nextPageIndx = abs((this->nextPageIndx+(1*n))%3);
    setPagepoint();
    ifstream file(this->File);
    this->docCIndx = this->docCIndx+(1*n);
    file.seekg(*(this->docCIndx+(1*n)));

    if(n==1){
        loadNewPage(&file,this->nextPage);
    }else{
        loadNewPage(&file,this->prevPage);
    }

    this->pageRecord.push_back(file.tellg());
    file.close();

}




vector<Album>* Page_Controler::returnNext(){
    return this->nextPage;

}

vector<Album>* Page_Controler::returnCurr(){
    return this->currPage;
}

vector<Album>* Page_Controler::returnPrev(){
    return this->prevPage;
}
