#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
static void numbers(const string& prefix, int k) {
    if (k == 0) {
        cout << prefix << std::endl;
    } else {
        numbers(prefix + "0", k - 1);
        numbers(prefix + "1", k - 1);
    }
}

void solve(){
    string prefix;
    cin>>prefix;
    int k;
    cin>>k;
    numbers(prefix, k);
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
