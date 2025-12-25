#include <iostream>
#include <conio.h>
#include <string>
#include "singer.h"
#include "playlist.h"
#include <unistd.h>

using namespace std;

void SingerMenu(Singer& singers, PlayList& playlists);
void PlaylistMenu(Singer& singers, PlayList& playlists);

int main(){
    Singer singers(100, 100);
    PlayList playlists(100, 100);
    char choice;
    while(1){
        system("cls || clear");
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << YELLOW << "*" << RESET << "   " << MAGENTA << "Music Management System" << RESET << "   " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "          " << GREEN << "Singers (1" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "        " << GREEN << "Playlists (2" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "             " << GREEN << "Exit (3" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << BLUE << "Please enter your choise: " << RESET;
        choice = getch() - '0';
        switch(choice){
            case 1:
                SingerMenu(singers, playlists);
                break;
            case 2:
                PlaylistMenu(singers, playlists);
                break;
            case 3:
                return 0;
                break;
            default:
                system("cls || clear");
                cout << RED << "Please enter your choise correctly." << RESET;
                usleep(2000000);
        }
    }
}

void SingerMenu(Singer& singers, PlayList& playlists){
    string Name, Lyrics;
    string text[20];
    char choice;
    SingerData* singerdata_temp;
    int check, choice_id, year, music_id;
    Song song_temp;
    while(1){
        system("cls || clear");
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << YELLOW << "*" << RESET << "        " << MAGENTA << "Singers Menu" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "        " << GREEN << "adds name (0" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "          " << GREEN << "dels id (1" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "          " << GREEN << "find id (2" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "           " << GREEN << "prints (3" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "              " << GREEN << "cls (4" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "        " << GREEN << "find name (5" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "             " << GREEN << "delm (6" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "            " << GREEN << "addms (7" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "           " << GREEN << "search (8" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "           " << GREEN << "countw (9" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "             " << GREEN << "back (b" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << BLUE << "Please enter your choise: " << RESET;

        choice = getch();
        if(choice == 'b'){
            return;
        }
        choice = choice - '0';

        switch(choice){
            case 0:
                system("cls || clear");
                cout << BLUE << "Please enter your name: "  << RESET;
                cin >> Name;
                check = singers.adds_name(Name);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 1:
                system("cls || clear");
                cout << BLUE << "Please enter your id: "  << RESET;
                cin >> choice_id;
                check = singers.dels_id(choice_id);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 2:
                system("cls || clear");
                cout << BLUE << "Please enter your id: "  << RESET;
                cin >> choice_id;
                singerdata_temp = singers.find_id(choice_id);
                if(singerdata_temp == nullptr){
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << GREEN << "ID : " << singerdata_temp->Id << endl;
                    cout << "Name : " << singerdata_temp->Name << endl;
                    if(singerdata_temp->SongsData.empty()){
                        cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                        cout << MAGENTA << "The desired singer does not have any songs..."  << RESET << endl;
                    }
                    for(int i = 0; i < singerdata_temp->SongsData.get_size(); i++){
                        song_temp = singerdata_temp->SongsData.get_index(i);
                        cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                        cout << BLUE << "ID : " << song_temp.getId() << endl;
                        cout << "Name : " << song_temp.getName() << endl;
                        cout << "Year : " << song_temp.getYear() << endl;
                        cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
                    }
                    cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                    cout << "Please press a button..." ;
                    getch();
                }
                break;
            case 3:
                system("cls || clear");
                singers.prints();
                cout << "Please press a button..." ;
                getch();
                break;
            case 4:
                singers.cls();
                system("cls || clear");
                cout << GREEN << "All singers were successfully deleted..."  << RESET;
                usleep(2000000);
                break;
            case 5:
                system("cls || clear");
                cout << BLUE << "Please enter the music name: "  << RESET;
                cin >> Name;
                system("cls || clear");
                singers.find_name(Name);
                cout << "Please press a button..." ;
                getch();
                break;
            case 6:
                system("cls || clear");
                cout << BLUE << "Please enter the artist id: "  << RESET;
                cin >> choice_id;
                cout << BLUE << endl << "Pleas enter the music id: " << RESET;
                cin >> music_id;
                check = singers.delm_artist(music_id, choice_id);
                if(check == 1){
                    playlists.del_music_all(music_id);
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 7:
                system("cls || clear");
                cout << BLUE << "Please enter the music name: " << RESET;
                cin >> Name;
                cout << BLUE << endl << "Pleas enter the music year: " << RESET;
                cin >> year;
                cout << BLUE << endl << "Pleas enter the artist ID: " << RESET;
                cin >> choice_id;
                cout << BLUE << endl << "Enter the lyrics and at the end enter 0 on a separate line:" << endl << RESET;
                int i;
                for(i = 0; i < 20; i++){
                    getline(cin, text[i]);
                    if(text[i] == "0"){
                        break;
                    }
                }
                for(int j = 0; j < i ; j++){
                    if(text[j] != ""){
                        Lyrics += text[j];
                        if(j != i - 1){
                            Lyrics += "\n"; 
                        }
                    }
                }
                check = singers.addms(Name, year, Lyrics, choice_id);
                Lyrics = "";
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 8:
                system("cls || clear");
                cout << BLUE << endl << "Pleas enter the artist ID: " << RESET;
                cin >> choice_id;
                cout << BLUE << endl << "Pleas enter the music ID: " << RESET;
                cin >> music_id;
                cout << BLUE << endl << "Plear enter the word: " << RESET;
                cin >> Name;
                check = singers.search(choice_id, music_id, Name);
                cout << MAGENTA << endl << "The index of word is(If the index was -1, it doesn't exist.): " << RESET << GREEN << check << RESET << endl;
                cout << "Please press a button..." ;
                getch();
                break;
            case 9:
                system("cls || clear");
                cout << BLUE << endl << "Pleas enter the artist ID: " << RESET;
                cin >> choice_id;
                cout << BLUE << endl << "Pleas enter the music ID: " << RESET;
                cin >> music_id;
                cout << BLUE << endl << "Plear enter the word: " << RESET;
                cin >> Name;
                check = singers.countw(choice_id, music_id, Name);
                cout << MAGENTA << endl << "The number of repeated words in the desired music text is: " << RESET << GREEN << check << RESET << endl;
                cout << "Please press a button..." ;
                getch();
                break;
            default:
                system("cls || clear");
                cout << RED << "Please enter your choise correctly." << RESET;
                usleep(2000000);
        }
    }
}

void PlaylistMenu(Singer& singers, PlayList& playlists){
    char choice;
    string Name;
    int check, music_id, playlist_id, artist_id;
    Song song_temp;
    while(1){
        system("cls || clear");
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << YELLOW << "*" << RESET << "      " << MAGENTA << "Play List Menu" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "        " << GREEN << "addp name (0" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "            " << GREEN << "addmp (1" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "          " << GREEN << "searchp (2" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "          " << GREEN << "searchm (3" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "            " << GREEN << "delmp (4" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "            " << GREEN << "showp (5" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "            " << GREEN << "addqp (6" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "              " << GREEN << "pop (7" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "             " << GREEN << "back (b" << RESET << "         " << YELLOW << "*" << RESET << endl;
        cout << YELLOW << "*" << RESET << "                             " YELLOW << "*" << RESET << endl;
        cout << YELLOW << "* * * * * * * * * * * * * * * *" << RESET << endl;
        cout << BLUE << "Please enter your choise: " << RESET;

        choice = getch();
        if(choice == 'b'){
            return;
        }
        choice = choice - '0';
    

        switch(choice){
            case 0:
                system("cls || clear");
                cout << BLUE << "Please enter your name: "  << RESET;
                cin >> Name;
                check = playlists.addp_name(Name);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 1:
                system("cls || clear");
                cout << BLUE << "Please enter your play list id: "  << RESET;
                cin >> playlist_id;
                cout << BLUE << endl << "Pleas enter your artist id: " << RESET;
                cin >> artist_id;
                cout << BLUE << endl << "Pleas enter the music id: " << RESET;
                cin >> music_id;
                check = playlists.addmp(music_id, playlist_id, artist_id, &singers);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 2:{
                system("cls || clear");
                cout << BLUE << "Please enter your id: "  << RESET;
                cin >> playlist_id;
                PlayListData *data = playlists.searchp(playlist_id);
                system("cls || clear");
                cout << GREEN << "ID : " << data->Id << endl;
                cout << "Name : " << data->Name << endl;
                if(data->SongsData.empty()){
                    cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                    cout << MAGENTA << "The desired play list does not have any songs..."  << RESET << endl;
                }
                for(int i = 0; i < data->SongsData.get_size(); i++){
                    song_temp = data->SongsData.get_index(i);
                    cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                    cout << BLUE << "ID : " << song_temp.getId() << endl;
                    cout << "Name : " << song_temp.getName() << endl;
                    cout << "Year : " << song_temp.getYear() << endl;
                    cout << "Lyrics : " << song_temp.getLyrics() << endl << RESET;
                }
                cout << YELLOW << "* * * * * * * * * * * * * * * * * * * * *" << RESET << endl;
                cout << "Please press a button..." ;
                getch();
                break;
            }
            case 3:
                system("cls || clear");
                cout << BLUE << "Please enter your play list id: "  << RESET;
                cin >> playlist_id;
                cout << BLUE << endl << "Pleas enter your music id: " << RESET;
                cin >> music_id;
                system("cls || clear");
                playlists.searchm(playlist_id, music_id);
                cout << "Please press a button..." ;
                getch();
                break; 
            case 4:
                system("cls || clear");
                cout << BLUE << "Please enter your play list id: "  << RESET;
                cin >> playlist_id;
                cout << BLUE << endl << "Pleas enter your music id: " << RESET;
                cin >> music_id;
                check = playlists.delmp(playlist_id, music_id);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 5:
                system("cls || clear");
                cout << BLUE << "Please enter your play list id: "  << RESET;
                cin >> playlist_id;
                system("cls || clear");
                playlists.showp(playlist_id); 
                cout << "Please press a button..." ;
                getch();
                break;
            case 6:
                system("cls || clear");
                cout << BLUE << "Please enter your play list id: "  << RESET;
                cin >> playlist_id;
                system("cls || clear");
                check = playlists.addqp(playlist_id);
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            case 7:
                system("cls || clear");
                check = playlists.pop();
                if(check == 1){
                    system("cls || clear");
                    cout << GREEN << "The operation was successful..."  << RESET;
                    usleep(2000000);
                }
                else{
                    system("cls || clear");
                    cout << RED << "There was a problem, please try again..."  << RESET;
                    usleep(2000000);
                }
                break;
            default:
                system("cls || clear");
                cout << RED << "Please enter your choise correctly." << RESET;
                usleep(2000000);
        }
    }
}