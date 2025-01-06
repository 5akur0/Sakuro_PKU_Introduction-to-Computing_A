#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> myfriends(n);
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--;
        b--;
        myfriends[a].push_back(b);
        myfriends[b].push_back(a);
    }

    vector<int> Condition(n);
    for (int i = 0; i < n; ++i) {
        Condition[i] = 0;
    }

    int f;
    cin >> f;
    Condition[f - 1] = 1;
    
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-comparison"
    for (int t = 0; t < 200000000; t++) {
        for (int i = 0; i < n; ++i) {
            if (Condition[i] == 0) {
                for (int j = 0; j < myfriends[i].size(); ++j) {
                    if (Condition[myfriends[i][j]] == 1) {
                        Condition[i] = -1;
                        break;
                    }
                }
            }
        }
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (Condition[i] == -1) {
                flag = false;
                Condition[i] = 1;
            }
            else if (Condition[i] == 1) {
                Condition[i] = 2;
            }
            else if (Condition[i] == 2) {
                Condition[i] = 0;
            }
        }
        if (flag) {
            cout << t + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
    #pragma GCC diagnostic pop
}