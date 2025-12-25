#include "playlist.h"

int PlayList::IdGenerator = 0;

PlayList::PlayList(int _MaxValue, int _Capacity):MaxValue(_MaxValue), Capacity(_Capacity), N(0), PlayListQueue(_Capacity){
    Sparse = new int[_MaxValue + 1];
    Dense = new PlayListData[_Capacity];
    for(int i = 0; i < _MaxValue + 1; i++){
        Sparse[i] = Capacity + 1;
    }
}

bool PlayList::addp_name(string Name){
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

bool PlayList::addmp(int MusicId, int PlayListId, int ArtistId, Singer *Data){
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N) {
        return 0;
    }
    SingerData *temp = Data->find_id(ArtistId);
    if(temp == nullptr){
        return 0;
    }
    for(int i = 0; i < temp->SongsData.get_size(); i++){
        if(temp->SongsData.get_index(i).getId() == MusicId){
            int index = Sparse[PlayListId];
            Dense[index].SongsData.push_back(temp->SongsData.get_index(i));
            return 1;
        }
    }
    return 0;
}

PlayListData* PlayList::binary_search(int PlayListId, int left, int right){
    if (left > right) {
        return nullptr;
    }

    int mid = left + (right - left) / 2;

    if (Dense[mid].Id == PlayListId) {
        return &Dense[mid];
    } else if (Dense[mid].Id < PlayListId) {
        return binary_search(PlayListId, mid + 1, right);
    } else {
        return binary_search(PlayListId, left, mid - 1);
    }
}

PlayListData* PlayList::searchp(int PlayListId) {
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N) {
        return nullptr;
    }
    return binary_search(PlayListId, 0, N - 1);
}

bool PlayList::searchm (int PlayListId, int MusicId){
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N) {
        return 0;
    }
    int index = Sparse[PlayListId];
    for(int i = 0; i < Dense[index].SongsData.get_size(); i++){
        if(Dense[index].SongsData.get_index(i).getId() == MusicId){
            Song song_temp = Dense[index].SongsData.get_index(i);
            cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
            cout << BLUE << "ID : " << song_temp.getId() << endl;
            cout << "Name : " << song_temp.getName() << endl;
            cout << "Year : " << song_temp.getYear() << endl;
            cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
            return 1;
        }
    }
    cout << YELLOW << "--------------------------------------------------" << RESET << endl;
    return 0;
}

bool PlayList::delmp(int PlayListId, int MusicId){
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N) {
        return 0;
    }
    int index = Sparse[PlayListId];
    for(int i = 0; i < Dense[index].SongsData.get_size(); i++){
        if(Dense[index].SongsData.get_index(i).getId() == MusicId){
            Dense[index].SongsData.del_index(i);
            return 1;
        }
    }
    return 0;
}

void PlayList::del_music_all(int MusicId){
    for(int i = 1; i <= N; i++){
        this->delmp(i, MusicId);
    }
}

void PlayList::showp(int PlayListId){
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N) {
        return;
    }
    int index = Sparse[PlayListId];
    Dense[index].SongsData.SortByYear();
    Song song_temp;
    for(int i = 0; i < Dense[index].SongsData.get_size(); i++){
        song_temp = Dense[index].SongsData.get_index(i);
        cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
        cout << BLUE << "ID : " << song_temp.getId() << endl;
        cout << "Name : " << song_temp.getName() << endl;
        cout << "Year : " << song_temp.getYear() << endl;
        cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
    }
    cout << YELLOW << "--------------------------------------------------" << RESET << endl; 
}

bool PlayList::addqp(int PlayListId){
    if (PlayListId <= 0 || PlayListId > MaxValue || Sparse[PlayListId] >= N || PlayListQueue.isFull()) {
        return 0;
    }
    PlayListData *temp = searchp(PlayListId);
    if(temp == nullptr){
        return 0;
    }
    PlayListQueue.enqueue(*temp);
    return 1;
}

bool PlayList::pop(){
    if(PlayListQueue.isEmpty()){
        return 0;
    }
    PlayListQueue.dequeue();
    return 1;
}