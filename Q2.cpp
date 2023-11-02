#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    vector<string>men ={"he","him","his","himself"},wem ={" or she"," or her"," or her"," or herself"};
    string s,s2;
    getline(cin,s);
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]>='A'&&s[i]<='z'||s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
            if(isupper(s[i])){ s2 += tolower(s[i]); }
            else{s2+=s[i];}
        }
        else{
            for (int j = 0; j < 4; ++j) {
                if(s2==men[j]){
                    s.insert(i,wem[j]);
                    i+=wem[j].size();
                }
            }
            s2.clear();
        }
    }
    cout<<s;
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
