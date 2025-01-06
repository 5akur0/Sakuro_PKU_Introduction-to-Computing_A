#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > map(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            cin >> ch;
            if (ch == '*') {
                map[i][j] = true;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j]) {
                cout << '*';
            }
            else {
                int count = 0;
                for (int x = max(i - 1, 0); x < min(i + 2, n); ++x) {
                    for (int y = max(j - 1, 0); y < min(j + 2, m); ++y) {
                        if (map[x][y]) {
                            count++;
                        }
                    }
                }
                cout << count;
            }
        }
        cout << endl;
    }
    return 0;
}