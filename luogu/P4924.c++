#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > map(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            map[i][j] = 1 + n * i + j;
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        int xb = x - r - 1;
        int xe = x - 1;
        int yb = y + r - 1;
        int ye = y;
        if (z == 0) {
            for (int X = xb; X <= xe; ++X) {
                for (int Y = ye; Y <= yb; ++Y) {
                    int tmp = map[X][Y];
                    map[X][Y] = map[x + y - 2 - Y][y - x + X];
                    map[x + y - 2 - Y][y - x + X] = map[2 * x - 2 - X][2 * y - 2 - Y];
                    map[2 * x - 2 - X][2 * y - 2 - Y] = map[x - y + Y][x + y - 2 - X];
                    map[x - y + Y][x + y - 2 - X] = tmp;
                }
            }
        }
        else {
            for (int X = xb; X <= xe; ++X) {
                for (int Y = ye; Y <= yb; ++Y) {
                    int tmp = map[X][Y];
                    map[X][Y] = map[x - y + Y][x + y - 2 - X];
                    map[x - y + Y][x + y - 2 - X] = map[2 * x - 2 - X][2 * y - 2 - Y];
                    map[2 * x - 2 - X][2 * y - 2 - Y] =  map[x + y - 2 - Y][y - x + X];
                    map[x + y - 2 - Y][y - x + X] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            cout << map[i][j] << " ";
        }
        cout << map[i][n - 1] << endl;
    }
}