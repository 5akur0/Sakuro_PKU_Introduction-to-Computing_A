#include <bits/stdc++.h>
using namespace std;

const int N = 8;
const int TOTAL = 92;
bool col[N], dg[2 * N - 1], udg[2 * N - 1];
vector<int> ansList;

void DFS(int row, int current) {
    if (row >= N) {
        ansList.push_back(current);
        return;
    }
    for (int c = 0; c < N; ++c) {
        if (col[c] && dg[row + c] && udg[N - 1 + row - c]) {
            col[c] = dg[row + c] = udg[N - 1 + row - c] = false;
            DFS(row + 1, current * 10 + (c + 1));
            col[c] = dg[row + c] = udg[N - 1 + row - c] = true;
        }
    }
}

int main() {
    fill(begin(col), end(col), true);
    fill(begin(dg), end(dg), true);
    fill(begin(udg), end(udg), true);
    DFS(0, 0);
    if (ansList.size() != TOTAL) {
        cout << "ERROR" << endl;
        return 0;
    }
    
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        if (m >= 1 && m <= TOTAL) {
            cout << ansList[m - 1] << endl;
        } else {
            cout << "Index out of range" << endl;
        }
    }
}
