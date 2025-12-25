#ifndef SINGER_H
#define SINGER_H

#include <iostream>
#include "singerdata.h"
#include <string>

using namespace std;

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define RESET   "\x1b[0m"

class Singer{
private:
    SingerData *Dense;
    int *Sparse;        
    int N;              
    int Capacity;       
    int MaxValue;     
    static int IdGenerator;
    static int SongIdGenerator;

public:
    Singer(int _MaxValue, int _Capacity);

    bool adds_name(string Name);

    bool dels_id(int Id);

    SingerData* find_id(int Id);

    void prints();

    void cls();

    void find_name(string MusicName);

    bool delm_artist(int MusicId, int Id);

    bool addms(string MusicName,int Year, string Content, int ArtistId);

    void sort_sparse();

    void quick_sort(int low, int high);

    int partition(int low, int high);

    int search(int ArtistId, int MusicId, string Word);
    
    int countw(int ArtistId, int MusicId, string Word);
};

#endif