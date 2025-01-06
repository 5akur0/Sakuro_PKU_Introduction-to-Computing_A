#include <bits/stdc++.h>
using namespace std;
int t;
int n, m;
long long s[10005];

// C++初始模板程序

int main() {
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        cin >> n >> m;
        for (int i = 0; i <= m; ++i) {
            cin >> s[i];
        }
        stringstream oss;
        int cur = 1;
        vector<int> a;
        a.push_back(0);
        while (true) {
            while (s[cur] == 0) {
                cur++;
                if (cur > m) {
                    break;
                }
            }
            if (cur > m || a.size() >= n + 1) {
                break;
            }
            while (s[cur] > 0) {
                a.push_back(cur);
                for (int j = 0; j < a.size() - 1; ++j) {
                    s[cur + a[j]]--;
                }
            }
        }
        for (int i = 1; i < a.size(); ++i) {
            oss << a[i] << " ";
        }
        string output = oss.str();
        output.pop_back();
        cout << output << endl;
    }
    return 0;
}
