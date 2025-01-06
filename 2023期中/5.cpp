#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }
    int m, n, d;
    cin >> m >> n >> d;
    if (matrix[m][n] == 1) {
        cout << 1 << endl;
        return 0;
    }
    matrix[m][n] = 2;
    for (int D = 0; D < d; ++D) {
        vector<int> update_x;
        vector<int> update_y;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][j] == 0) {
                    if ((i - 1 >= 0 && matrix[i - 1][j] == 2) || (j - 1 >= 0 && matrix[i][j - 1] == 2) ||
                        (i + 1 < N && matrix[i + 1][j] == 2) || (j + 1 < N && matrix[i][j + 1] == 2)) {
                        update_x.push_back(i);
                        update_y.push_back(j);
                    }
                }
                else if (matrix[i][j] == 1) {
                    if (i - 1 >= 0 && matrix[i - 1][j] == 2 && j - 1 >= 0 && matrix[i][j - 1] == 2 &&
                        i + 1 < N && matrix[i + 1][j] == 2 && j + 1 < N && matrix[i][j + 1] == 2) {
                        update_x.push_back(i);
                        update_y.push_back(j);
                    }
                }
            }
        }
        for (int t = 0; t < update_x.size(); ++t) {
            matrix[update_x[t]][update_y[t]] += 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (matrix[i][j] >= 2) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}