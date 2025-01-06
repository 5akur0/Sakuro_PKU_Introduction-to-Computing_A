#include <bits/stdc++.h>
using namespace std;

int DFS(bool last, bool current, const vector<bool> &input, int index) {
    if (index == input.size() - 1) {
        if (input[index]) {
            if (last != current) {
                return 1;
            }
            return 0;
        }
        if (last == current) {
            return 1;
        }
        return 0;
    }
    if (input[index]) {
        if (last && !current) {
            return DFS(false, false, input, index + 1);
        }
        if (!last && current) {
            return DFS(true, true, input, index + 1) + DFS(true, false, input, index + 1);
        }
        if (!last && !current) {
            return DFS(false, true, input, index + 1);
        }
        return 0;
    }
    if (last && current) {
        return DFS(true, false, input, index + 1) + DFS(true, true, input, index + 1);
    }
    if (last && !current) {
        return DFS(false, true, input, index + 1);
    }
    if (!last && !current) {
        return DFS(false, false, input, index + 1);
    }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int _ = 0; _ < m; ++_) {
        vector<bool> input(n);
        char b;
        for (int i = 0; i < n; ++i) {
            cin >> b;
            input[i] = false;
            if (b == '1') {
                input[i] = true;
            }
        }
        cout << DFS(false, true, input, 0) + DFS(false, false, input, 0) << endl;
    }
}