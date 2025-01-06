#include <bits/stdc++.h>
using namespace std;

bool DFS(const int L, const int n, int _L, int m, 
int i_min, vector<int> &l, vector<bool> &available) {
    if (m == 0) {
        return true;
    }
    if (_L == L) {
        return DFS(L, n, 0, m - 1, 0, l, available);
    }
    for (int i = i_min; i < n; ++i) {
        if (available[i] && _L + l[i] <= L) {
            available[i] = false;
            if (DFS(L, n, _L + l[i], m, i + 1, l, available)) {
                return true;
            }
            available[i] = true;
            //剪枝
            if (_L == 0) {
                return false;
            }
            while (i + 1 < n && l[i + 1] == l[i]) {
                i++;
            }
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        int sum = 0;
        vector<int> l(n);
        vector<bool> available(n, true);
        for (int i = 0; i < n; ++i) {
            cin >> l[i];
            sum += l[i];
        }
        sort(l.begin(), l.end(), [](const int &a, const int &b){
            return a > b;
        });
        for (int L = l[0]; L <= sum; ++L) {
            if (sum % L) {
                continue;
            }
            int num = sum / L;
            if (DFS(L, n, 0, num, 0, l, available)) {
                cout << L << endl;
                break;
            }
        }
    }
    return 0;
}