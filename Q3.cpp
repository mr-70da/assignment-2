#include <bits/stdc++.h>
using namespace std;
#define ii int
#define vi vector <int> v ;
#define vll vector<ll>;
#define ss string
#define f(i,a,b)      for(ll i=a;i<b;i++)
#define fr(i,a,b)     for(ii i=b-1;i>=0;i--)
#define ll long long
ll calc(ll x1 , ll y1 , ll x2 , ll y2)
{
    ll ans = (y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1);
    return ans;
}
//mahmoud ayman **************************************
vector<string> split(string target, char delimiter){
    vector<string>splited_text;
    string temp;
    for(int i =0  ; i<target.size();i++ ){
        if(target[i] == delimiter)
        {
            splited_text.push_back(temp);
            temp="";
        }
        else{
            temp += target[i];
        }
    }splited_text.push_back(temp);
    return splited_text;

}
int main() {
    string c;char i;
    cin>>c>>i;
    vector<string>v=split(c,i);
    for(auto I :v){
        cout<<I<<" ";
}



}
