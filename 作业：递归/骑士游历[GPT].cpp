#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int di[N] = {2, 2, -2, -2, 1, 1, -1, -1};
const int dj[N] = {1, -1, 1, -1, 2, -2, 2, -2};

int bfs(pair<int, int> start, pair<int, int> end) {
    vector<vector<int>> dp(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push(start);
    dp[start.first][start.second] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == end.first && y == end.second)
            return dp[x][y];

        for (int k = 0; k < N; ++k) {
            int nx = x + di[k];
            int ny = y + dj[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && dp[nx][ny] == -1) {
                dp[nx][ny] = dp[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}

int main() {
    string start, end;
    string line;
    while (getline(cin, line)) {
        stringstream iss(line);
        iss >> start >> end;
        int x = start[0] - 'a';
        int y = start[1] - '1';
        int m = end[0] - 'a';
        int n = end[1] - '1';

        int ans = bfs({x, y}, {m, n});
        cout << "To get from " << start << " to " << end << " takes " << ans << " knight moves." << endl;
    }
    return 0;
}
