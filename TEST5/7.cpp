#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    int matrix[4][4] = {{0,2,5,9},{1,4,8,12},{3,7,11,14},{6,10,13,15}};
    while (true) {
        vector<int> addList;
        cin >> n >> x >> y;
        if (n == 0) {
            break;
        }
        int a, b;
        while (x >= 4 || y >= 4) {
            a = x % 4;
            b = y % 4;
            x /= 4;
            y /= 4;
            addList.push_back(matrix[a][b]);
        }
        addList.push_back(matrix[x][y]);
        int ans = 0;
        for (int i = 0; i < addList.size(); ++i) {
            ans += pow(16, i) * addList[i];
        }
        cout << ans << endl;
    }
    return 0;
}