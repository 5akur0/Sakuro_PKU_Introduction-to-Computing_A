#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int bestLeft, bestRight;
    int currentLeft, currentRight;
    int tempBestLeft;
    int previousLeft, previousRight;

    cin >> currentLeft >> currentRight;

    //第一行初始化
    bestLeft = 2 * currentRight - currentLeft - 1;
    bestRight = currentRight - 1;

    for (int i = 2; i <= n; ++i) {
        previousLeft = currentLeft;
        previousRight = currentRight;

        cin >> currentLeft >> currentRight;

        //状态转移方程
        tempBestLeft = min(abs(previousLeft - currentRight) + bestLeft,
                           abs(previousRight - currentRight) + bestRight) + currentRight - currentLeft + 1;
        bestRight = min(abs(previousLeft - currentLeft) + bestLeft,
                        abs(previousRight - currentLeft) + bestRight) + currentRight - currentLeft + 1;
        bestLeft = tempBestLeft;
    }

    cout << min(n - currentLeft + bestLeft, n - currentRight + bestRight) << endl;
    return 0;
}
