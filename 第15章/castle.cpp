#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, -1, 0, 1 };
const int dy[4] = { -1, 0, 1, 0 };
const int walls[4] = { 1, 2, 4, 8 };

void visit(int x, int y, vector<vector<int>>& castle, vector<vector<bool>>& visited, int count)
{
    visited[x][y] = true;
    count++;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < castle.size() && ny >= 0 && ny < castle[0].size() && !visited[nx][ny] && !(castle[x][y] & walls[i])) {
            visit(nx, ny, castle, visited, count);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> castle(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> castle[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;
    int maxRoomSize = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!visited[i][j]) {
                int roomSize = 0;
                visit(i, j, castle, visited, roomSize);
                roomCount++;
                maxRoomSize = max(maxRoomSize, roomSize);
            }
        }
    }

    cout << roomCount << endl;
    cout << maxRoomSize << endl;

    return 0;
}