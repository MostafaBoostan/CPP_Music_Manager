#include "singer.h"

int Singer::IdGenerator = 0;
int Singer::SongIdGenerator = 0;

Singer::Singer(int _MaxValue, int _Capacity): MaxValue(_MaxValue), Capacity(_Capacity), N(0){
    Sparse = new int[_MaxValue + 1];
    Dense = new SingerData[_Capacity];
    for(int i = 0; i < _MaxValue + 1; i++){
        Sparse[i] = Capacity + 1;
    }
}

bool Singer::adds_name(string Name) {
    int i;
    if (N >= Capacity){
        return 0;
    }
    IdGenerator ++;

    Dense[N].Id = IdGenerator;
    Dense[N].Name = Name;

    Sparse[IdGenerator] = N;
    N++;
    return 1;
}

bool Singer::dels_id(int Id){
    if (Id <= 0 || Id > MaxValue || Sparse[Id] >= N) {
        return 0;
    }
    int index = Sparse[Id]; 
    Sparse[Id] = Capacity + 1;

    Dense[index] = Dense[N - 1];
    Sparse[Dense[index].Id] = index; 
    N--;  
    
    /*
    You can not use it and there will be no problem, 
    and this line is only placed so that all ID information is in order for printing,
    and if it raises the order and this is not the purpose, you can delete this line.
    */
    sort_sparse(); 

    return 1;           
}

SingerData* Singer::find_id(int Id){
    if (Id <= 0 || Id > MaxValue || Sparse[Id] >= N) {
        return nullptr;
    }
    int index = Sparse[Id];
    return &Dense[index];
}

void Singer::prints(){
    Song song_temp;
    if(N == 0){
        cout << MAGENTA << "There is no singer..."  << RESET << endl;
        cout << YELLOW << "--------------------------------------------------" << RESET << endl;
    }
    for(int i = 0; i < N; i++){
        cout << GREEN << "ID : " << Dense[i].Id << endl;
        cout << "Name : " << Dense[i].Name << endl;
        if(Dense[i].SongsData.empty()){
            cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
            cout << MAGENTA << "The desired singer does not have any songs..."  << RESET << endl;
        }
        for(int j = 0; j < Dense[i].SongsData.get_size(); j++){
            song_temp = Dense[i].SongsData.get_index(j);
            cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
            cout << BLUE << "ID : " << song_temp.getId() << endl;
            cout << "Name : " << song_temp.getName() << endl;
            cout << "Year : " << song_temp.getYear() << endl;
            cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
        }
        cout << YELLOW << "--------------------------------------------------" << RESET << endl;
    }
}

void Singer::cls(){
    N = 0;
}

void Singer::find_name(string MusicName){
    Song song_temp;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < Dense[i].SongsData.get_size(); j++){
            song_temp = Dense[i].SongsData.get_index(j);
            if(song_temp.getName() == MusicName){
                cout << BLUE << "Singer ID : " << Dense[i].Id << endl;
                cout << "Music ID : " << song_temp.getId() << endl;
                cout << "Name : " << song_temp.getName() << endl;
                cout << "Year : " << song_temp.getYear() << endl;
                cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
                cout << YELLOW << "--------------------------------------------------" << RESET << endl;
            }
        }
    }
}

bool Singer::delm_artist(int MusicId, int Id){
    if (Id <= 0 || Id > MaxValue || Sparse[Id] >= N) {
        return 0;
    }
    int index = Sparse[Id];
    for(int i = 0; i < Dense[index].SongsData.get_size(); i++){
        if(Dense[index].SongsData.get_index(i).getId() == MusicId){
            Dense[index].SongsData.del_index(i);
            return 1;
        }
    }
    return 0;
}

bool Singer::addms(string MusicName,int Year, string Content, int ArtistId){
    if (ArtistId <= 0 || ArtistId > MaxValue || Sparse[ArtistId] >= N) {
        return 0;
    }
    int index = Sparse[ArtistId];
    SongIdGenerator++;
    Song temp(Year, MusicName, Content, SongIdGenerator);
    Dense[index].SongsData.push_back(temp);
    return 1;
}

void Singer::sort_sparse() {
    quick_sort(0, N - 1);
}

void Singer::quick_sort(int low, int high) {
    if (low < high) {
        int pivotIndex = partition(low, high);
        quick_sort(low, pivotIndex - 1);
        quick_sort(pivotIndex + 1, high);
    }
}

int Singer::partition(int low, int high) {
    int pivot = Dense[low].Id;
    int i = low;
    int j = high;

    while (i < j) {
        while (Dense[i].Id < pivot) {
            i++;
        }

        while (Dense[j].Id > pivot) {
            j--;
        }

        if (i < j) {
            swap(Dense[i], Dense[j]);
            swap(Sparse[Dense[i].Id], Sparse[Dense[j].Id]);
        }
    }

    return j;
}

int Singer::search(int ArtistId, int MusicId, string Word){
    if (ArtistId <= 0 || ArtistId > MaxValue || Sparse[ArtistId] >= N) {
        return -1;
    }
    int index = Sparse[ArtistId];
    if(MusicId > Dense[index].SongsData.get_size()){
        return -1;
    }
    Song temp = Dense[index].SongsData.get_index(MusicId - 1);
    return Dense[index].SongsData.get_index(MusicId - 1).search(Word);
}

int Singer::countw(int ArtistId, int MusicId, string Word){
    if (ArtistId <= 0 || ArtistId > MaxValue || Sparse[ArtistId] >= N) {
        return 0;
    }
    int index = Sparse[ArtistId];
    if(MusicId > Dense[index].SongsData.get_size()){
        return 0;
    }
    return Dense[index].SongsData.get_index(MusicId - 1).countw(Word);
}