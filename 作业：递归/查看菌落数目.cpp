#include <bits/stdc++.h>
using namespace std;

const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, 1, 0, -1};

void DFS(vector<vector<int>>& matrix, int i, int j) {
    if (matrix[i][j] == 0) {
        return;
    }
    matrix[i][j] = 0;
    for (int k = 0; k < 4; ++k) {
        int i_ = i + di[k];
        int j_ = j + dj[k];
        if (i_ >= 0 && i_ < matrix.size() && j_ >= 0 && j_ < matrix[0].size() && matrix[i_][j_] == 1) {
            DFS(matrix, i_, j_);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                continue;
            }
            ans++;
            DFS(matrix, i, j);
        }
    }
    cout << ans << endl;
    return 0;
}