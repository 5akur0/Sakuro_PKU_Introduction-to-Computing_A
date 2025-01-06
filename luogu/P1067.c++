#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int coefficient;
    for (int i = n; i > -1; --i) {
        cin >> coefficient;
        if (coefficient < 0) {
            coefficient = -coefficient;
            cout << "-";
        }
        else if (i != n && coefficient != 0) {
            cout << "+";
        }
        if (coefficient != 0) {
            if (coefficient != 1 || i == 0) {
                cout << coefficient;
            }
            if (i != 0) {
                if (i == 1) {
                    cout << "x";
                }
                else {
                    cout << "x^" << i;
                }
            }
        }
    }
    cout << endl;
    return 0;
}