#include "song.h"

Song::Song(int _Year, string _Name, string _Lyrics, int _Id): Year(_Year), Name(_Name), Lyrics(_Lyrics) {
    Id = _Id;
    Length = _Lyrics.size();
    SuffixArray = buildSuffixArray(_Lyrics, Length);
}

Song::Song(): Year(0), Name(""), Lyrics("") {
    Id = 0;
    Length = 0;
    SuffixArray = nullptr;
}

int Song::getId(){
    return Id;
}
int Song::getYear(){
    return Year;
}
string Song::getName(){
    return Name;
}
string Song::getLyrics(){
    return Lyrics;
}
void Song::set_Id(int Id){
    this->Id = Id;
}

void Song::quickSort(suffix arr[], int low, int high){
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Song::partition(suffix arr[], int low, int high){
    suffix pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


bool Song::compare(suffix a, suffix b){
    if (a.rank[0] == b.rank[0]){
        return a.rank[1] < b.rank[1];
    }
    return a.rank[0] < b.rank[0];
}

int* Song::buildSuffixArray(string& txt, int n){
    struct suffix suffixes[n];

    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i];
        suffixes[i].rank[1] = ((i + 1) < n) ? txt[i + 1] : -1;
    }

    quickSort(suffixes, 0, n - 1);

    int ind[n];

    for (int k = 4; k < 2 * n; k = k * 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank &&
                suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else { 
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++) {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextindex < n) ? suffixes[ind[nextindex]].rank[0] : -1;
        }

        quickSort(suffixes, 0, n - 1);
    }

    int* suffixArr = new int[n];
    for (int i = 0; i < n; i++){
        suffixArr[i] = suffixes[i].index;
    }

    return suffixArr;
}

int Song::search(string& pat){
    int n = Lyrics.size();
    int m = pat.size(); 
    int low = 0, high = n - 1; 

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int start = SuffixArray[mid];
        int i = 0;
        while (i < m && start + i < n && Lyrics[start + i] == pat[i]) {
            i++;
        }

        if (i == m) {
            return start;
        } else if (i < m && (start + i >= n || Lyrics[start + i] < pat[i])) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int Song::countw(string& pat) {
    int count = 0;
    int n = Lyrics.size();
    int m = pat.size();

    int lps[m];  
    int len = 0;  
    lps[0] = 0;  

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; 
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    int j = 0;  
    i = 0; 
    while (i < n) {
        if (pat[j] == Lyrics[i]) {
            i++;
            j++;
        }

        if (j == m) {
            count++;
            j = lps[j - 1];  
        } else if (i < n && pat[j] != Lyrics[i]) {
            if (j != 0) {
                j = lps[j - 1];  
            } else {
                i++;
            }
        }
    }

    return count;
}
