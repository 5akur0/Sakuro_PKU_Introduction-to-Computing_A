#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flg = false;
    int k, n1, n2, n3, n4, n5;
    int x, a, b, c, d, e;
    cin >> k >> n1 >> n2 >> n3 >> n4 >> n5;
    int A = 1 - n5 + n5 * n4 - n5 * n4 * n3 + n5 * n4 * n3 * n2;
    int B = 1 + n1 * n2 * n3 * n4 * n5;
    for (int i = 1; i <= 100 * k; ++i) {
        if (A * i % B == 0) {
            x = i;
            set<int> check;
            check.clear();
            a = A * x / B;
            check.insert(a);
            b = x - n1 * a;
            check.insert(b);
            c = x - n2 * b;
            check.insert(c);
            d = x - n3 * c;
            check.insert(d);
            e = x - n4 * d;
            check.insert(e);
            if (check.size() == 5) {
                cout << x << " " << a << " " << b << " " << c << " " << d << " " << e;
                flg = true;
                break;
            }
        }
    }
    if (!flg) {
        cout << "not found" << endl;
    }
    return 0;
}