#include <iostream>
#include <string>
#include <utility>
#include "Song.h"
using namespace std;


Song::Song(string title, string artist, int size){
    this->title=move(title);
    this->artist=move(artist);
    if(size>0){
        this->size=size;
    }
    else{
        exit(1);
    }
}
string Song::getTitle(){
    return this->title;
}
void Song::setTitle(string newTitle){
    this->title=move(newTitle);
}
string Song::getArtist(){
    return this->artist;
}
void Song::setArtist(string newArtist){
    this->artist=move(newArtist);
}
int Song::getSize(){
    return this->size;
}
void Song::setSize(int newSize){
    this->size=newSize;
}
bool Song::operator==(const Song& rhs){
    return this->size == rhs.size && this->title == rhs.title && this->artist == rhs.artist;
}
bool Song::operator<(const Song& rhs){
    if(this->artist<rhs.artist){ return true; }
    else if(this->artist==rhs.artist){
        if(this->title<rhs.title){ return true; }
        else if(this->title==rhs.title){
            return this->size<rhs.size;
        }
        else{ return false; }
    }
    else{ return false; }
}
bool Song::operator>(const Song& rhs){
    if(this->artist>rhs.artist){ return true; }
    else if(this->artist==rhs.artist){
        if(this->title>rhs.title){ return true; }
        else if(this->title==rhs.title){
            return this->size>rhs.size;
        }
        else{ return false; }
    }
    else{ return false; }
}