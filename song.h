#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

struct suffix {
    int index; 
    int rank[2];
};

class Song {
private:
    int Id;
    int Year;
    string Name;
    string Lyrics;
    int* SuffixArray;
    int Length;

public:
    int getId();
    int getYear();
    string getName();
    string getLyrics();
    void set_Id(int Id);
    Song(int _Year, string _Name, string _Lyrics, int _Id);
    Song();
    void quickSort(suffix arr[], int low, int high);
    int partition(suffix arr[], int low, int high);
    bool compare(suffix a, suffix b);
    int* buildSuffixArray(string& txt, int n);
    int search(string& pat);
    int countw(string& pat);
};

#endif
