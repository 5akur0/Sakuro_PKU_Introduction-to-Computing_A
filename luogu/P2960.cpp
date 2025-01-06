#include <bits/stdc++.h>
using namespace std;

int X, Y, Mx, My, t;
int mat[105][105];
bool visited[105][105];

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

struct node {
    int x, y, day;
};

int main() {
    char ch;
    cin >> X >> Y >> Mx >> My;
    for (int j = Y; j >= 1; --j) {
        for (int i = 1; i <= X; ++i) {
            cin >> ch;
            if (ch == '.') {
                mat[i][j] = 1;
            }
        }
    }
    queue<node> q;
    q.push({Mx, My, 0});
    visited[Mx][My] = true;
    while (!q.empty()) {
        node n = q.front();
        q.pop();
        t = n.day + 1;
        for (int i = 0; i < 8; ++i) {
            int nx = n.x + dx[i];
            int ny = n.y + dy[i];
            if (nx < 1 || nx > X || ny < 1 || ny > Y) {
                continue;
            }
            if (visited[nx][ny]) {
                continue;
            }
            if (mat[nx][ny] == 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, t});
            }
        }
    }
    cout << t - 1 << endl;
    return 0;
}