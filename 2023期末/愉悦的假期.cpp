#include <bits/stdc++.h>
using namespace std;
char mat[55][55];
char cmat[55][55];
vector<pair<int, int>> A;
vector<pair<int, int>> B;
vector<pair<int, int>> C;
int N, M;

void dfs(int x, int i, int j) {
    if (mat[i][j] != 'X') {
        return;
    }
    if (x == 0) {
        A.push_back(make_pair(i, j));
    }
    if (x == 1) {
        B.push_back(make_pair(i, j));
    }
    if (x == 2) {
        C.push_back(make_pair(i, j));
    }
    mat[i][j] = '.';
    if (i - 1 >= 1) {
        dfs(x, i - 1, j);
    }
    if (j - 1 >= 1) {
        dfs(x, i, j - 1);
    }
    if (i + 1 <= N) {
        dfs(x, i + 1, j);
    }
    if (j + 1 <= M) {
        dfs(x, i, j + 1);
    }
}

int dist(pair<int, int> M, pair<int, int> N) {
    return (abs(M.first - N.first) + abs(M.second - N.second) - 1);
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cmat[i][j] = mat[i][j];
        }
    }
    int now = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (mat[i][j] == 'X') {
                dfs(now, i, j);
                now++;
                if (now > 2) {
                    break;
                }
            }
        }
    }
    int a = 1005, b = 1005, c = 1005;
    for (int i = 0; i < B.size(); ++i) {
        for (int j = 0; j < C.size(); ++j) {
            a = min(a, dist(B[i], C[j]));
        }
    }
    for (int i = 0; i < C.size(); ++i) {
        for (int j = 0; j < A.size(); ++j) {
            b = min(b, dist(C[i], A[j]));
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < B.size(); ++j) {
            c = min(c, dist(A[i], B[j]));
        }
    }
    int ans = INT_MAX;
    ans = min(ans, a + b);
    ans = min(ans, b + c);
    ans = min(ans, a + c);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (cmat[i][j] == '.') {
                int ta = 1005, tb = 1005, tc = 1005;
                for (int k = 0; k < A.size(); ++k) {
                    ta = min(ta, dist(make_pair(i, j), A[k]));
                }
                for (int k = 0; k < B.size(); ++k) {
                    tb = min(tb, dist(make_pair(i, j), B[k]));
                }
                for (int k = 0; k < C.size(); ++k) {
                    tc = min(tc, dist(make_pair(i, j), C[k]));
                }
                ans = min(ans, ta + tb + tc + 1);
            }
        }
    }
    cout << ans << endl;

    return 0;
}