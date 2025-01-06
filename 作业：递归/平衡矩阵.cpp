#include <bits/stdc++.h>
using namespace std;

int DFS(vector<vector<int>> &matrix, int row) {
    if (row == matrix.size()) {
        int maxColSum = 0;
        for (int col = 0; col < matrix.size(); ++col) {
            int colSum = 0;
            for (int row = 0; row < matrix.size(); ++row) {
                colSum += matrix[row][col];
            }
            maxColSum = max(maxColSum, colSum);
        }
        return maxColSum;
    }

    int minMaxColSum = INT_MAX;
    for (int shift = 0; shift < matrix.size(); ++shift) {
        minMaxColSum = min(minMaxColSum, DFS(matrix, row + 1));
        int temp = matrix[row][0];
        for (int col = 0; col < matrix.size() - 1; ++col) {
            matrix[row][col] = matrix[row][col + 1];
        }
        matrix[row][matrix.size() - 1] = temp;
    }
    return minMaxColSum;
}

int main() {
    int n;
    while (cin >> n && n != -1) {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> matrix[i][j];
        cout << DFS(matrix, 0) << endl;
    }
    return 0;
}
