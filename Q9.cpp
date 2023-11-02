#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
static bool bears(int n){
    if(n==42){
        return true;
    }
    if(n%5!=0&&n%2!=0&&n%3!=0&&n%4!=0){
        return false;
    }
    if(n/2==42){
        return true;
    }
    if(n%2==0&&n%100!=50&&n%10!=5&&((n%100)/10)!=5&&n>42||n==50){
        return bears(n/2);
    }
    if(n%3==0&&n%10*((n%100)/10)!=0||n%4==0&&n%10*((n%100)/10)!=0){
        int x;
        x=n%10*((n%100)/10);
        return bears(x);
    }
    if(n%5==0){
        if(n>42) {
            n -= 42;
            return bears(n);
        }
        else{
            return true;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    if(bears(n)){
        cout<<"You have reached the goal!\n";
    }
    else{
        cout<<"You lost\n";
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
