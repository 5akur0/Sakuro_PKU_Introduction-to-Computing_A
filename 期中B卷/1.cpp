#include <bits/stdc++.h>
using namespace std;

int main() {
    float a, b;
    cin >> a >> b;
    cout << fixed << setprecision(2) << a * b / pow((a * a + b * b), 0.5) << endl;
    return 0;
}