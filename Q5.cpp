//mahmoud ayman **problem 5.
#include <bits/stdc++.h>
using namespace std;
#define ii int
#define vi vector <int> v ;
#define vll vector<ll>;
#define ss string
#define f(i,a,b)      for(ll i=a;i<b;i++)
#define fr(i,a,b)     for(ii i=b-1;i>=0;i--)
#define ll long long
multimap<int,string,greater<int>>playerList;
void menu();
void AddNewPlayer();
void PrintingPlayers();
void showScore();
bool exist = false;
int main() {
    cout<<"Ahlan ya user ya habibi \uF04A\n";

    while(!exist){
        menu();
    }

}
void AddNewPlayer(){
    cout<<"Please enter your player name and his score separated by space eg:(Mahmoud 10)";
    string name; int score;
    cin>>name>>score;
    playerList.insert(make_pair(score,name));
}
void PrintingPlayers(){
    int counter=0;
    for(auto I : playerList){
        cout<<I.second<<" "<<I.first<<"\n";
        counter++;
        if(counter==10){
            break;
        }
    }
}
void showScore(){
    cout<<"Please enter the player's name";
    string playername;
    cin>>playername;
    int counter=0;
    bool found =0;
    int key = 0;
    string value = playername;
    for(auto entry : playerList){
        counter++;
        if(entry.second == value)
        {
            key = entry.first;
            found=1;
            break;
        }
    }if(counter<=10 && found){
        cout<<key<<"\n";
    }else if(counter<=10){
        cout<<"The player’s name is not in the top 10";
    }else{
        cout<<"The player’s name has not been input";
    }
}
void menu(){
    char option;
    cout<<"please select one of the options:\n"
        <<"(a) Adding a new player.\n"
        <<"(b) Printing top scores' players.\n"
        <<"(c) Enter a player name to show his score.\n"
        <<"(0) Exist\n";

    cin>>option;
    option= tolower(option);
    switch (option) {
        case 'a':
            AddNewPlayer();
            break;
        case 'b':
            PrintingPlayers();
            break;
        case 'c':
            showScore();
            break;
        case '0':
            exist =1;
            break;
        default:
            cout << "Please try a vaild selection:\n";
            break;

    }
}
