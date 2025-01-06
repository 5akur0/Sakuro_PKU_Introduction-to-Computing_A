#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<char>> input(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> input[i][j];
        }
    }
    vector<vector<char>> output(N, vector<char>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> output[i][j];
        }
    }
    // 1 顺时针
    bool flg = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (input[i][j] != output[j][N - 1 - i]) {
                flg = false;
                break;
            }
        }
        if (!flg) {
            break;
        }
    }
    if (flg) {
        cout << 1 << endl;
        return 0;
    }

    // 2 逆时针
    flg = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (input[i][j] != output[N - 1 - j][i]) {
                flg = false;
                break;
            }
        }
        if (!flg) {
            break;
        }
    }
    if (flg) {
        cout << 2 << endl;
        return 0;
    }

    // 3 对称
    flg = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (input[i][j] != output[N - 1 - i][N - 1 - j]) {
                flg = false;
                break;
            }
        }
        if (!flg) {
            break;
        }
    }
    if (flg) {
        cout << 3 << endl;
        return 0;
    }

    // 4 不变
    flg = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (input[i][j] != output[i][j]) {
                flg = false;
                break;
            }
        }
        if (!flg) {
            break;
        }
    }
    if (flg) {
        cout << 4 << endl;
        return 0;
    }

    cout << 5 << endl;
    return 0;
}