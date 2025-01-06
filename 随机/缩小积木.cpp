#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> H(n), T(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> H[i];
    }

    T[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (H[i] > H[i - 1]) {
            T[i] = T[i - 1] + 1;
        } else if (H[i] < H[i - 1]) {
            T[i] = 1;
        } else {
            T[i] = T[i - 1];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (H[i] > H[i + 1]) {
            T[i] = max(T[i], T[i + 1] + 1);
        }
        else if (H[i] == H[i + 1]) {
            T[i] = T[i + 1];
        }
    }

    int total_height = 0;
    for (int i = 0; i < n; ++i) {
        total_height += T[i];
    }

    cout << total_height << endl;
    return 0;
}
