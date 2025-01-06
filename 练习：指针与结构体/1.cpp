#include <bits/stdc++.h>
using namespace std;

int main() {
    float input;
    cin >> input;
    union {
        float f;
        uint32_t i;
    } u;
    u.f = input;
    cout << hex << setw(8) << setfill('0') << u.i << endl;
    return 0;
}