#include <bits/stdc++.h>
using namespace std;

int boardWidth, boardHeight, startX, startY, endX, endY;
vector<vector<char>> board;
vector<vector<int>> visited;
int minSegments = INT_MAX;
const int dx[4] = {-1, 0, 1, 0};  // 四个方向：上、左、下、右
const int dy[4] = {0, -1, 0, 1};
int boardCount = 0;

void dfs(int x, int y, int segments, int direction) {
    if (segments >= minSegments) return;
    if (x == endX && y == endY) {
        minSegments = segments;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i], nextY = y + dy[i];
        if (nextX >= 0 && nextX <= boardWidth + 1 && nextY >= 0 && nextY <= boardHeight + 1 &&
            ((board[nextX][nextY] == ' ' && visited[nextX][nextY] == 0) || (nextX == endX && nextY == endY))) {
            visited[nextX][nextY] = 1;
            if (direction == i) {
                dfs(nextX, nextY, segments, i);
            }
            else {
                dfs(nextX, nextY, segments + 1, i);
            }
            visited[nextX][nextY] = 0;
        }
    }
}

int main() {
    while (cin >> boardHeight >> boardWidth) {
        if (boardHeight == 0 && boardWidth == 0) {
            break;
        }
        cin.ignore();

        board.assign(boardWidth + 2, vector<char>(boardHeight + 2, ' '));
        visited.assign(boardWidth + 2, vector<int>(boardHeight + 2, 0));

        string line;
        for (int i = 1; i <= boardWidth; i++) {
            getline(cin, line);
            for (int j = 1; j <= boardHeight; j++) {
                board[i][j] = line[j - 1];
            }
        }

        int pairCount = 0;
        boardCount++;
        cout << "Board #" << boardCount << ":\n";

        while (cin >> startY >> startX >> endY >> endX) {
            if (startX == 0 && startY == 0 && endX == 0 && endY == 0) {
                break;
            }
            pairCount++;
            minSegments = INT_MAX;
            fill(visited.begin(), visited.end(), vector<int>(boardHeight + 2, 0));
            dfs(startX, startY, 0, -1);

            if (minSegments != INT_MAX) {
                cout << "Pair " << pairCount << ": " << minSegments << " segments." << endl;
            }
            else {
                cout << "Pair " << pairCount << ": impossible." << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
