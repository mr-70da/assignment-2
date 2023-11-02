#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct dominoT {
    int leftDots;
    int rightDots;
};

istream & operator >> (istream& input,dominoT& d){
    input>>d.leftDots>>d.rightDots;
    return input;
}
ostream & operator<<(ostream& output, dominoT& d){
    output<<d.leftDots<<"|"<<d.rightDots;
    return output;
}
bool FormsDominoChain(vector<dominoT>& dominos,vector<dominoT>& chain,int n ,int count) {
    if (n == count) {
        return true;
    }
    for (int i = 0;i<dominos.size();++i) {

        if (chain.empty() || (chain.back().rightDots == dominos[i].leftDots)) {

            chain.push_back(dominos[i]);
            dominos.erase(dominos.begin()+i);
            if (FormsDominoChain(dominos, chain,n+1,count)) {
                return true;
            }
            dominos.insert(dominos.begin()+i,chain.back());
            chain.pop_back();
        }
    }
    // No valid domino found, return false
    return false;
}
void solve(){
    int count,count_input = 0;cout<<"please enter the number of dominos: \n";
    cin>>count;
    vector<dominoT>domino(count),domino_game;
    for (int i = 0; i < count; ++i) {
        cout<<"please put the dominos number "<<++count_input<<" :\n";
        cin>>domino[i];
    }
    if(FormsDominoChain(domino,domino_game,0,count)){
        cout<<"Yes\n";
        cout<<"Chain:\n";
        for (int i = 0; i < domino_game.size(); ++i) {
            cout<<domino_game[i]<<(i!=domino_game.size()-1 ? " - ":"");
        }
    }
    else{
        cout<<"No\n";
    }
}
int main() {
    ios::sync_with_stdio(true);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}
