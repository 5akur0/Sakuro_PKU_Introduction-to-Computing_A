#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string input;
    for (int i = 0; i < n; ++i) {
        cin >> input;
        bool f = true;
        for (int j = 0; j < input.size() - 1; ++j) {
            if (input[j] >= 'a' && input[j] <= 'c' && input[j] == input[j + 1]) {
                f = false;
                break;
            }
        }
        if (f) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}