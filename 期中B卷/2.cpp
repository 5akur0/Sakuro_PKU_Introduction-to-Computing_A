#include <bits/stdc++.h>
using namespace std;

int main()
{
    double m;
    cin >> m;
    double d = 0.0;
    if (m <= 0.4883 * 240) {
        d = m / 0.4883;
    } else if (m <= 0.4883 * 240 + 0.5383 * 160) {
        d = 240 + (m - 0.4883 * 240) / 0.5383;
    } else {
        d = 400 + (m - 0.4883 * 240 - 0.5383 * 160) / 0.7883;
    }

    cout << fixed << setprecision(2) << d << endl;

    return 0;
}