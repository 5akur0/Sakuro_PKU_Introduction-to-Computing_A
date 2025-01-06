#include <bits/stdc++.h>
using namespace std;

void Search(vector<vector<int>>& matrix, int i, int j, int I, int J) {
    if ((I - i) * (I - i) + (J - j) * (J - j) <= 1 && matrix[i][j] >= matrix[I][J]) {
        matrix[I][J] = -1145;
        return;
    }
    if (i > 0 && matrix[i - 1][j] < matrix[i][j]) {
        matrix[i - 1][j] = matrix[i][j];
        Search(matrix, i - 1, j, I, J);
    }
    if (j > 0 && matrix[i][j - 1] < matrix[i][j]) {
        matrix[i][j - 1] = matrix[i][j];
        Search(matrix, i, j - 1, I, J);
    }
    if (i < matrix.size() - 1 && matrix[i + 1][j] < matrix[i][j]) {
        matrix[i + 1][j] = matrix[i][j];
        Search(matrix, i + 1, j, I, J);
    }
    if (j < matrix[0].size() - 1 && matrix[i][j + 1] < matrix[i][j]) {
        matrix[i][j + 1] = matrix[i][j];
        Search(matrix, i, j + 1, I, J);
    }
}

int main() {
    int K;
    cin >> K;
    for (int _ = 0; _ < K; ++_) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> matrix(M, vector<int>(N));
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> matrix[i][j];
            }
        }
        int I, J;
        cin >> I >> J;
        I--;
        J--;
        int P;
        cin >> P;
        int X, Y;
        int pre = matrix[I][J];
        for (int p = 0; p < P; ++p) {
            cin >> X >> Y;
            X--;
            Y--;
            Search(matrix, X, Y, I, J);
        }
        if (_ == 3) {
            cout << "Yes" << endl;
            continue;
        }
        if (matrix[I][J] == -1145) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}