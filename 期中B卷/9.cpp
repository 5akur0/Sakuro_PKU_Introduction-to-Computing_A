#include <bits/stdc++.h>
using namespace std;

bool canSustainTime(const vector<int>& time, int n, int k, double mid)
{
    double total = 0;
    for (int i = 0; i < n; ++i) {
        total += min(double(time[i]), mid);
    }
    return total >= mid * k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> time(n);
    for (int i = 0; i < n; ++i) {
        cin >> time[i];
    }

    double left = 0, right = accumulate(time.begin(), time.end(), 0.0) / k;
    while (right - left > 1e-6) {
        double mid = (left + right) / 2;
        if (canSustainTime(time, n, k, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(3) << left << endl;
    return 0;
}