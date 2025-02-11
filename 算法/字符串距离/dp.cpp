#include <bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    if (n * m == 0) return n + m;
    vector<vector<int>> D(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j < m + 1; j++) {
        D[0][j] = j;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int left = D[i - 1][j] + 1;
            int down = D[i][j - 1] + 1;
            int left_down = D[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1]) left_down += 1;
            D[i][j] = min(left, min(down, left_down));
        }
    }
    return D[n][m];
}

int main() {
    int n;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; ++i) {
        cin >> s1 >> s2;
        int move = minDistance(s1, s2);
        cout << fixed << setprecision(6) << 1/(move + 1.0) << endl;
    }
}

