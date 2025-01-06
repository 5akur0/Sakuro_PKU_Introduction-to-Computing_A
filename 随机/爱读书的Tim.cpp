#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> reference(n);
    vector<bool> ifRead(n);
    for (int i = 0; i < n; ++i) {
        cin >> reference[i];
        ifRead[i] = false;
    }
    int day = 0;
    int check = 0;
    int min_book = 0;
    while (true) {
        day++;
        int book;
        for (int i = min_book; i < n; ++i) {
            if (!ifRead[i]) {
                book = i;
                min_book = i + 1;
                break;
            }
        }
        
        while (true) {
            ifRead[book] = true;
            check++;
            if (!ifRead[reference[book] - 1]) {
                book = reference[book] - 1;
            }
            else {
                break;
            }
        }
        if (check >= n) {
            break;
        }
    }
    cout << day << endl;
    return 0;
}