#include <bits/stdc++.h>
using namespace std;

struct Circle {
    int x, y, r;
};

int main() {
    int n;
    cin >> n;
    vector<Circle> circles(n);
    for (int i = 0; i < n; ++i) {
        cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    string ans = "No";
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dis = (circles[i].x - circles[j].x) * (circles[i].x - circles[j].x) + (circles[i].y - circles[j].y) * (circles[i].y - circles[j].y);
            if (dis < (circles[i].r + circles[j].r) * (circles[i].r + circles[j].r)) {
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}