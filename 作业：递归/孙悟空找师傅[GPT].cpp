#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Position {
    int x;
    int y;
};

bool bfs(vector<vector<int>>& matrix, Position start, Position end) {
    int m = matrix.size();
    int n = matrix[0].size();
    queue<Position> q;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Position current = q.front();
        q.pop();
        if (current.x == end.x && current.y == end.y) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = current.x + directions[i][0];
            int ny = current.y + directions[i][1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] != 1 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    Position start, end;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                start = {i, j};
            } else if (matrix[i][j] == 3) {
                end = {i, j};
            }
        }
    }

    if (bfs(matrix, start, end)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
