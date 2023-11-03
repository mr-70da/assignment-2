#include "Bigreal.cpp"
using namespace std;
void solve(){
    string s1,s2,s3;
    cin>>s1>>s2;
    Bigreal b(s1),c(s2);
    b.print_number_sign_real();
    c.print_number_sign_real();
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
