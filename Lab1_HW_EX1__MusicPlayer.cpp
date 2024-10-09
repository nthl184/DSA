/*
MSSV: 22520772
Full name: Nguyen Thi Huyen Linh
Homework Exercise - Problem 1 - Music player
*/
#include <iostream>
#include <string>
using namespace std;

class song //create node of a song
{public:
    string name;
    song *next;
    song *prev;
    song(string n)
    {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};
class MusicPlayer //create a music player
{public:
    song *Head = nullptr;
    song *Tail = nullptr;

//add a song
    void addSong(string n, song *&crt)
    {
        song *newSong = new song(n);
        if(Head == nullptr)
        {
            Head = Tail = crt = newSong;
            Head->next = Head->prev = Head;
        }
        else
        {
            Tail->next = newSong;
            newSong->prev = Tail;
            newSong->next = Head;
            Head->prev = newSong;
            Tail = newSong;
        }
    }
//play next and prev
    void playNext(song *&crt)
    {
        crt = crt->next;
    }
    void playPrev(song *&crt)
    {
        crt = crt->prev;
    }
//remove a song
    void removeSong(string n, song *&crt)
    {
        song *tmp = Head;
        //found the location where the song needs to be removed
        while(tmp->name!=n)
        {
            if(tmp == Tail) break;
            tmp= tmp->next;
        }
        //check if the song that needs to be deleted exists or not.
        if(tmp == Tail && tmp->name !=n)
            return; //stop if the song needs to be removed doesn't exist

        if(tmp==Head && tmp==Tail) //the music player has 1 song
            { Head = Tail = crt = nullptr; }
        else //the musicplayer has more 1 song
        {
            if(tmp == Head) //tmp is head that that needs to be removed
                Head = Head->next;
            if(tmp == Tail)
                Tail = Tail->prev;
            if(crt == tmp) crt=crt->next;
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        delete tmp;
        return;
    }
//display music player
    void display(song *crt)
    {
        if (!Head) {
            cout << "Playlist is empty\n";
            return;
        }
        song *tmp = crt;
        do
        {
            cout<<tmp->name<<" ";
            tmp = tmp->next;
        }
        while(tmp!=crt);
        cout<<'\n';
    }
};
int main()
{
    freopen("exer.inp","r",stdin);
    MusicPlayer p;
    song *crt = nullptr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s == "ADD")
        {
            cin>>s;
            p.addSong(s,crt);
            continue;
        }
        if(s == "NEXT") { p.playNext(crt); continue; }
        if(s == "PREV") { p.playPrev(crt); continue; }
        if(s == "REMOVE")
        {
            cin>>s;
            p.removeSong(s,crt);
            continue;
        }
        if(s == "DISPLAY") { p.display(crt); }
    }
    return 0;
}
