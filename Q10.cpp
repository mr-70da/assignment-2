#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
vector<string>names={"Hamas","Palestine","Gaza","Jewish","Israel","resistance"
,"shoot","Zionists","Zionism"};
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
void encryption(string& s){
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]>='a'&&s[i]<='z'&&i!=s.size()-1||s[i]>='A'&&s[i]<='Z'&&i!=s.size()-1){
            s.insert(i,"\u0336");
            i+=2;
        }
    }
}
void solve(){
    string Filename,Filename2,x,y;
    cin>>Filename>>Filename2;
    Filename+=".txt";
    Filename2+=".txt";
    ifstream fil1(Filename,ios::in);
    ofstream fil2(Filename2,ios::in);
    while(getline(fil1,x)){
        y = "";
        vector<string>words;
        words = split(x);
        for (int i = 0; i < words.size(); ++i) {
            if(count(names.begin(), names.end(),words[i])){
                encryption(words[i]);
            }
            y+=words[i]+" ";
        }
        fil2<<y;
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
