#include <bits/stdc++.h>
#define ll long long
using namespace std;
const unsigned long long N = 2e6 + 5;
void printStars(int n, int i) {
    if (n <= 0) {
        return;
    }
    if (n == 1) {
        for (int j = 0; j < i; ++j) {
            cout << "  ";
        }
        cout << "*";
    } else {
        printStars(n / 2, i);
        cout << endl;
        for (int j = 0; j < i; ++j) {
            cout << "  ";
        }
        for (int j = 0; j < n; ++j) {
            cout << "* ";
        }
        cout << endl;
        printStars(n / 2, i + n / 2);
    }
}

void pattern(int n, int i) {
    if (n <= 0) {
        return;
    }
    printStars(n, i);
}
void solve(){
    int n;
    cin>>n;
    pattern(n,0);
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
