#include <bits/stdc++.h>
using namespace std;
int up[2005][2005], leftArr[2005][2005], rightArr[2005][2005];
int maxSquareArea = 0, maxRectanArea = 0, board[2005][2005], m, n;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            up[i][j] = 1, leftArr[i][j] = j, rightArr[i][j] = j,
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (board[i][j] ^ board[i][j - 1]) {
                leftArr[i][j] = leftArr[i][j - 1];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j > 1; j--) {
            if (board[i][j] ^ board[i][j - 1]) {
                rightArr[i][j - 1] = rightArr[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i > 1 && board[i][j] ^ board[i - 1][j]) {
                up[i][j] = up[i - 1][j] + 1,
                leftArr[i][j] = min(leftArr[i][j], leftArr[i - 1][j]),
                rightArr[i][j] = min(rightArr[i][j], rightArr[i - 1][j]);
                int a = rightArr[i][j] - leftArr[i][j] + 1;
                int b = min(a, up[i][j]);
                maxSquareArea = max(maxSquareArea, b * b);
                maxRectanArea = max(maxRectanArea, a * up[i][j]);
            }
        }
    }

    cout << maxSquareArea << endl << maxRectanArea << endl;
}