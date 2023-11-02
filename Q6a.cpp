#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
string output;
static void binaryPrint(int n){
    if(n==0){
        return void(output+="0");
    }
    if (n==1){
        return void(output+="1");
    }
    else{
        binaryPrint(n / 2);
        if (n % 2 == 0) {
            return void(output+="0");
        }
        else {
            return void(output+="1");
        }
    }

}
void solve(){
    int input;cin>>input;
    binaryPrint(input);
    cout<<output;
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
