#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cout << "Please enter N: ";
    cin >> n;
     // n+1 to reach N and all digits start with true except arr[0] , arr[1]
    vector<bool> arr(n + 1, true);
    arr[0] = arr[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (arr[i]) {
            // j * i to delete multiples of a number
            for (int j = i ; j * i <= n; ++j) {
                arr[j * i] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (arr[i]) {
            cout << i << " ";
        }
    }
}
