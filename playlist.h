#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "playlistdata.h"
#include "singer.h"
#include "queue.h"

using namespace std;

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define RESET   "\x1b[0m"

class PlayList{
private:
    Queue<PlayListData> PlayListQueue;
    PlayListData *Dense;
    int *Sparse;        
    int N;              
    int Capacity;       
    int MaxValue;     
    static int IdGenerator;
public:
    PlayList(int _MaxValue, int _Capacity);

    bool addp_name(string Name);

    bool addmp(int MusicId, int PlayListId, int ArtistId, Singer *Data);

    PlayListData *binary_search(int PlayListId, int left, int right);

    PlayListData *searchp(int PlayListId);

    bool searchm (int PlayListId, int MusicId);

    bool delmp(int PlayListId, int MusicId);

    void del_music_all(int MusicId);

    void showp(int PlayListId);

    bool addqp(int PlayListId);

    bool pop();
};



#endif