#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<string>scams={"account verification","account suspended","Your account has been compromised","security alert","unusual activity detected"
,"confirm your identity","limited time offer","free prize","free gift","urgent action required","update your account information","verify your email",
"verify your password","claim your reward","claim your reward","tax refund","lottery winner","paypal","eBay","Amazon","Microsoft",
"Apple","Google","Facebook","Netflix","Bank of America","Wells Fargo","IRS (Internal Revenue Service)","social security administration",
"UPS","FedEx","DHL","Online Banking Alert","Payment Confirmation"};
map<string,int>mp;
void split(string& target,string& s){
    string temp;
    auto it = target.find(s);
    for(int i =(int)it  ; i< s.size()+(int)it;i++ ){
        temp +=target[i];
    }
    target.erase(target.begin()+(int)it,target.begin()+(int)s.size()+(int)it);
    auto found = target.find(s);
    mp[temp]++;
    if(found!=string::npos){
        split(target,s);
    }
}
void solve(){
    string Filename,x;
    cin>>Filename;
    Filename+=".txt";
    ifstream fil1(Filename,ios::in);
    int count =0;
    while(getline(fil1,x)) {
        for (int i = 0; i < scams.size(); ++i) {
            auto found = x.find(scams[i]);
            if(found!=string::npos){
                split(x,scams[i]);
            }
        }
    }
    for (auto& i:mp) {
        cout<<"the phrase or word : "<<i.first<<"\n"<<"has occurred: "<<i.second <<" times\n";
        count+=i.second;
    }
    cout<<"The Total score = "<<count<<"\n";
    if(count>=20){
        cout<<"it has a high point total to some actual phishing"
              " e-mails and also it has some legitimate e-mails you’ve received\n";
    }
    else{
        cout<<"It is not a phishing Email\n";
    }
    fil1.close();
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
