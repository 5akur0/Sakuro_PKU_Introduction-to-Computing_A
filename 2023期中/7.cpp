#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), [](const string &a, const string &b) {
        return a + b > b + a;
    });

    for (int i = 0; i < n; ++i) {
        cout << numbers[i];
    }
    cout << endl;
    
    return 0;
}