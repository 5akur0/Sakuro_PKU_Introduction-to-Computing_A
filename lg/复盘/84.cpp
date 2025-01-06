#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    int cur_count = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (cur_count + words[i].length() + 1 + words[i + 1].length() <= 80) {
            cur_count += words[i].length() + 1;
            cout << words[i] << " ";
        }
        else {
            cout << words[i] << endl;
            cur_count = 0;
        }
    }
    cout << words[n - 1] << endl;
    return 0;
}