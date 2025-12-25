#ifndef PLAYLISTDATA_H
#define PLAYLISTDATA_H

#include <iostream>
#include <string>
#include "linklist.h"

using namespace std;

class PlayListData{
public:
    int Id;
    string Name;
    LinkedList SongsData;
    PlayListData(int _Id, string _Name);
    PlayListData();
};

#endif