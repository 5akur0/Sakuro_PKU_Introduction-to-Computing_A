#include <bits/stdc++.h>
using namespace std;

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, 1, 0, -1};

int DFS(int i, int j, const vector<vector<int>> &matrix, vector<vector<int>> &count) {
    if (count[i][j] != 0) {
        return count[i][j];
    }
    count[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
        int i_ = i + di[k];
        int j_ = j + dj[k];
        if (matrix[i_][j_] < matrix[i][j]) {
            count[i][j] = max(count[i][j], DFS(i_, j_, matrix, count) + 1);
        }
    }
    return count[i][j];
}

int main() {
    int ans = 0;
    int R, C;
    cin >> R >> C;
    vector<vector<int>> matrix(R + 2, vector<int>(C + 2, INT_MAX)); 
    vector<vector<int>> count(R + 2, vector<int>(C + 2, 0)); 
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> matrix[i][j];
        }
    }
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            ans = max(ans, DFS(i, j, matrix, count));
        }
    }
    cout << ans << endl;
    return 0;
}
