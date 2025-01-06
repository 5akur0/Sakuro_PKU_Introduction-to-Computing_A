#include <bits/stdc++.h>
using namespace std;

int main() {

    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    int r, s;
    cin >> r >> s;
    vector<vector<int>> B(r, vector<int>(s));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < s; ++j) {
            cin >> B[i][j];
        }
    }
    
    int I, J;
    int min = INT_MAX;

    for (int i = 0; i <= m - r; ++i) {
        for (int j = 0; j <= n - s; ++j) {
            int cur = 0;
            for (int k = 0; k < r; ++k) {
                for (int l = 0; l < s; ++l) {
                    cur += abs(A[i + k][j + l] - B[k][l]);
                }
            }
            if (cur < min) {
                min = cur;
                I = i;
                J = j;
            }
        }
    }

    for (int i = I; i < I + r; ++i) {
        for (int j = J; j < J + s - 1; ++j) {
            cout << A[i][j] << ' ';
        }
        cout << A[i][J + s - 1] << endl;
    }
    return 0;
}
