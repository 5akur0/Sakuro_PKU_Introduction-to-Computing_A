#include <bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };

int tx, ty, sx, sy;

struct Node {
    int x, y, dist;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
            if (maze[i][j] == 'S') {
                sx = i;
                sy = j;
            } else if (maze[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    queue<Node> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    q.push({ sx, sy, 0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.x == tx && node.y == ty) {
            cout << node.dist << endl;
            return 0;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] != '#' && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({ nx, ny, node.dist + 1 });
            }
        }
    }

    cout << "No path found!" << endl;
    return 0;
}