#include "Song.h"
#include "UTPod.h"

UtPod::UtPod(){
    this->songs= nullptr;
    this->memSize=MAX_MEMORY;
}
UtPod::UtPod(int size){
    this->songs= nullptr;
    if(size<1||size>MAX_MEMORY){
        this->memSize=MAX_MEMORY;
    }
    else{
        this->memSize=size;
    }
}
void UtPod::shuffle() {
    SongNode* oldList=songs;
    songs= nullptr;
    while(oldList!=nullptr){
        addSong(getRandom(oldList));
    }
}
void UtPod::clearMemory() {
    SongNode* prevSong=this->songs;
    SongNode* current=this->songs->next;
    while(current!=nullptr){
        free(prevSong);
        prevSong=current;
        current=current->next;
    }
    songs=nullptr;
}
void UtPod::showSongList() {
    SongNode* current=this->songs;
    while(current!=nullptr){
        cout << current->s.getTitle() << ", " << current->s.getArtist() << ", " << current->s.getSize() << "MB" << endl;
        current=current->next;
    }
}
void UtPod::sortSongList() {
    SongNode* prevSong=this->songs;
    SongNode* current=this->songs->next;
    SongNode* nextSong=this->songs->next->next;
    while(!isSorted()){
        if(current->s>current->next->s){
            current->next=current->next->next;
            prevSong->next=current->next;

        }
        else{
            current=current->next;
        }
    }
}
int UtPod::getRemainingMemory() {
    int usedMem=0;
    SongNode* current=this->songs;
    while(current!=nullptr){
        usedMem+=current->s.getSize();
        current=current->next;
    }
    return this->memSize-usedMem;
}
int UtPod::addSong(const Song &s) {
    if(this->getRemainingMemory()<s.getSize()) return -1;
    SongNode* oldHead=this->songs;
    songs=(SongNode*)malloc(sizeof(SongNode));
    songs->s=s;
    songs->next=oldHead;
}
int UtPod::removeSong(const Song &s) {
    if(songs->next== nullptr && songs->s==s){
        free(songs);
        songs= nullptr;
        return 0;
    }
    if(songs->s==s){
        SongNode* temp=songs->next;
        free(songs);
        songs=temp;
        return 0;
    }
    SongNode* current=this->songs;
    SongNode* prevSong=current;
    while(current!=nullptr){
        if(current->s==s){
            prevSong->next=current->next;
            free(current);
            return 0;
        }
        prevSong=current;
        current=current->next;
    }
    return -2;
}
UtPod::~UtPod() {
    this->clearMemory();
}
bool UtPod::isSorted() {
    SongNode* current=this->songs;
    while(current->next!=nullptr){
        if(current->s>current->next->s){ return false; }
        current=current->next;
    }
    return true;
}
Song UtPod::getRandom(SongNode* s){
    int random=rand()%this->countSongs(s);
    SongNode* prevSong=s;
    SongNode* current=s->next;
    for(int i=0; i<random; i++){
        prevSong=current;
        current=current->next;
    }
    prevSong->next=current->next;
    Song song=current->s;
    free(current);
    return song;
}
int UtPod::countSongs(SongNode* s){
    int count=0;
    SongNode* current=this->songs;
    while(current!=nullptr){
        count++;
        current=current->next;
    }
    return count;
}