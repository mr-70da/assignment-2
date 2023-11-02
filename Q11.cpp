#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
vector<string> split(string target){
    vector<string>splited_text;
    string temp;
    for(int i =0  ; i<target.size();i++ ){
        if(target[i]>='a'&&target[i]<='z'||target[i]>='A'&&target[i]<='Z')
        {
            temp += target[i];
        }
        else{
            splited_text.push_back(temp);
            temp  ="";
        }
    }splited_text.push_back(temp);
    return splited_text;
}
void solve(){
    string Filename,Filename2,x,y;
    cin>>Filename>>Filename2;
    Filename+=".txt";
    Filename2+=".txt";
    ifstream fil1(Filename,ios::in);
    ifstream fil2(Filename2,ios::in);
    char operation;
    cout<<"choose a way of Comparison (c)haracter or (w)ord: \n";
    cin>>operation;
    int Countline=0;
    if(operation=='c'){
        bool equal = true;
        while (getline(fil1, x) && getline(fil2, y)) {
            Countline++;
            if(x.size()!=y.size()){
                cout<<Countline<<"\n"<<x<<'\n';
                equal ^= 1;
                goto end;
            }
            else{
                for (int i = 0; i < x.size(); ++i) {
                    if (x[i] != y[i]) {
                        cout<<Countline<<"\n"<<x<<'\n';
                        equal ^= 1;
                        goto end;
                    }
                }
            }
        }
        end:

        if (!equal) {
            cout << "not equal";
        } else {
            cout << "equal";
        }
    }
    else{
        bool equal = true;
        vector<string>word1,word2;
        while (getline(fil1, x) && getline(fil2, y)) {
            Countline++;
            word1 = split(x);
            word2 = split(y);
            for (int i = 0; i < word1.size(); ++i) {
                if (word1[i]!=word2[i]||i>=word2.size()||i==word1.size()-1&&word2.size()>word1.size()) {
                    cout<<Countline<<"\n"<<word1[i]<<'\n';
                    equal ^= 1;
                    goto last;
                }
            }
        }
        last:

        if (!equal) {
            cout << "not equal";
        } else {
            cout << "equal";
        }
    }
    fil1.close();
    fil2.close();
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
