#include <bits/stdc++.h>
using namespace std;

int N[7];

const int Magic = 100;

int main() {
    int _ = 0;
    while (true) {
        int zeroCount = 0;
        int target = 0;
        for (int i = 1; i <= 6; ++i) {
            cin >> N[i];
            if (N[i] == 0) {
                zeroCount++;
            }
            else if (N[i] % Magic == 0) {
                N[i] = Magic;
            }
            else {
                N[i] %= Magic;
            }
            target += N[i] * i;
        }
        if (zeroCount >= 6) {
            break;
        }
        if (_ != 0) {
            cout << endl;
        }
        _++;
        cout << "Collection #" << _ << ":" << endl;
        if (target % 2 == 1) {
            cout << "Can't be divided." << endl;
            continue;
        }
        target /= 2;
        for (int a = 0; a <= N[1]; ++a) {
            for (int b = 0; b <= N[2]; ++b) {
                for (int c = 0; c <= N[3]; ++c) {
                    for (int d = 0; d <= N[4]; ++d) {
                        for (int e = 0; e <= N[5]; ++e) {
                            for (int f = 0; f <= N[6]; ++f) {
                                if (1 * a + 2 * b + 3 * c + 4 * d + 5 * e + 6 * f == target) {
                                    cout << "Can be divided." << endl;
                                    goto end;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << "Can't be divided." << endl;
        end:;
    }
    return 0;
}