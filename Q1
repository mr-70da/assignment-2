#include <bits/stdc++.h>
#include <string>
using namespace std;
int main() {
    string a ;
    cout << "please enter the sentence" << endl;
    getline (cin, a, '.');
    for (int i = 0; i < a.size() ; ++i) {
        if (i == 0){
            a[i]= toupper(a[i]);
        }else if (a[i] == ','){
            continue;
        }else if (a[i] == ' ' && a[i+1] == ' '){
            a[i] = a[i+1];
        }else if (i !=0){
            a[i] = tolower(a[i]) ;
        }
    }
        cout << a ;
}
