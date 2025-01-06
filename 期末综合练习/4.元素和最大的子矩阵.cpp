#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mat[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
    }
    int mem[n + 1][n + 1];
    for (int i = 0; i < n; ++i) {
        mem[i + 1][0] = 0;
        for (int j = 0; j < n; ++j) {
            mem[i + 1][j + 1] = mem[i + 1][j] + mat[i][j];
        }
    }
    for (int j = 0; j <= n; ++j) {
        mem[0][j] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            mem[i][j] += mem[i - 1][j];
        }
    }
    int max_sum = INT_MIN;
    int max_i, max_j, max_k, max_l;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = i + 1; k <= n; ++k) {
                for (int l = j + 1; l <= n; ++l) {
                    if (mem[k][l] - mem[k][j] - mem[i][l] + mem[i][j] > max_sum) {
                        max_sum = mem[k][l] - mem[k][j] - mem[i][l] + mem[i][j];
                        max_i = i;
                        max_j = j;
                        max_k = k;
                        max_l = l;
                    }
                }
            }
        }
    }
    for (int i = max_i; i < max_k; ++i) {
        for (int j = max_j; j < max_l; ++j) {
            cout << mat[i][j];
            if (j < max_l - 1) {
                cout << " ";
            }
            else {
                cout << endl;
            }
        }
    }
    cout << max_sum << endl;
    return 0;
}