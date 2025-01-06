#include <bits/stdc++.h>
using namespace std;

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void Search(vector<vector<bool>> &matrix, int i, int j) {
    matrix[i][j] = false;
    for (int d = 0; d < 8; ++d) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni >= 0 && ni < matrix.size() && nj >= 0 && nj < matrix[0].size() && matrix[ni][nj]) {
            Search(matrix, ni, nj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> matrix(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            matrix[i][j] = (ch == '#');
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j]) {
                ++ans;
                Search(matrix, i, j);
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}