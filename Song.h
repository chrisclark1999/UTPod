#include <iostream>
#include <string>
using namespace std;

class Song{
private:
    string title;
    string artist;
    int size;
public:
    Song(string title, string artist, int size);
    string getTitle();
    void setTitle(string newTitle);
    string getArtist();
    void setArtist(string newArtist);
    int getSize();
    void setSize(int newSize);
    bool operator==(const Song& rhs);
    bool operator<(const Song& rhs);
    bool operator>(const Song& rhs);
};