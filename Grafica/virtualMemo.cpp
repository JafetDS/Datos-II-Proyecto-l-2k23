#include "virtualMemo.h"
using namespace std;
virtualMemo::virtualMemo(string file){
    this->File = file;
    this->prevPageIndx = 0;
    this->currPageIndx = 1;
    this->nextPageIndx = 2;
    streamoff n = 0;
    this->pageRecord.push_back(n);
}



void virtualMemo::fullPages(){
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

void virtualMemo::loadNewPage(ifstream* file,vector<Album>* Page){
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

void virtualMemo::setPagepoint(){
    this->prevPage = &this->Memo[this->prevPageIndx];
    this->currPage = &this->Memo[this->currPageIndx];
    this->nextPage = &this->Memo[this->nextPageIndx];
}





void virtualMemo::getnextPage(){
    if(*(this->docCIndx+2)!=-1){this->movePage(1);}

}

void virtualMemo::getprevPage(){
    if(*(this->docCIndx-2)!=0){this->movePage(-1);}


}


int virtualMemo::movePage(int n){

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
    return 0;
}

void virtualMemo::setUI(){

    vector<Album> prev = *this->prevPage;
    vector<Album> curr = *this->currPage;
    vector<Album> next = *this->nextPage;


    for(int i = 0; i < prev.size(); i++){
        this->list->addItem(QString::fromStdString(prev[i].id)+"_"+QString::fromStdString(prev[i].name));

    }

    for(int j = 0; j < curr.size(); j++){
        this->list->addItem(QString::fromStdString(curr[j].id)+"_"+QString::fromStdString(curr[j].name));

    }


    for(int k = 0; k < next.size(); k++){
        this->list->addItem(QString::fromStdString(next[k].id)+"_"+QString::fromStdString(next[k].name));

    }

    this->list->addItem(QString::fromStdString("a")+"_"+QString::fromStdString("b"));

}


vector<Album> virtualMemo::returnNext(){
    return *(this->nextPage);

}

vector<Album> virtualMemo::returnCurr(){
    return *(this->currPage);
}

vector<Album> virtualMemo::returnPrev(){
    return *(this->prevPage);
}

