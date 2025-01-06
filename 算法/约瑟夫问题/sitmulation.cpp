#include <bits/stdc++.h>
using namespace std;

int Solve(int k) {
    if (k == 1) {
        return 2;
    }
    int ans = k + 1;
    while (true) {
        vector<int> v;
        for (int i = 0; i < k; ++i) {
            v.push_back(0);
        }
        for (int i = 0; i < k; ++i) {
            v.push_back(1);
        }
        int cur = 0;
        int size = 2 * k;
        bool flag = true;
        for (int i = 0; i < k; ++i) {
            cur += ans - 1;
            cur %= size;
            if (v[cur] == 0) {
                flag = false;
                break;
            }
            v.erase(v.begin() + cur);
            size--;
            if (cur == size) {
                cur = 0;
            }
        }
        if (flag) {
            return ans;
        }
        ans++;
    }
    
}
int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cout << Solve(n) << endl;
    }
}