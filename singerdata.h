#ifndef SINGERDATA_H
#define SINGERDATA_H

#include <iostream>
#include <string>
#include "linklist.h"

using namespace std;

class SingerData{
public:
    int Id;
    string Name;
    LinkedList SongsData;
    SingerData(int _Id, string _Name);
    SingerData();
};

#endif