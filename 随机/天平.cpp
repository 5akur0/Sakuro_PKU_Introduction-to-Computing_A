#include <iostream>
using namespace std;
int C, G;
int h[21];
int w[21];
long dp[21][10005];
const int O = 5000;

// C++初始模板程序

int main() {
    cin >> C >> G;
    for (int i = 1; i <= C; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= G; ++i) {
        cin >> w[i];
    }
    dp[0][0 + O] = 1;
    for (int i = 1; i <= G; ++i) {
        for (int j = 1; j <= C; ++j) {
            for (int l = 0; l < 10005; ++l) {
                if (dp[i - 1][l] != 0) {
                    dp[i][l + w[i] * h[j]] += dp[i - 1][l];
                }
            }
        }
    }
    cout << dp[G][O] << endl;
    return 0;
}