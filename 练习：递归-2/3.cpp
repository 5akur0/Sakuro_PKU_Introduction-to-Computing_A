#include <bits/stdc++.h>
using namespace std;

int calculate(int M, int N) {
    if (M <= 1 || N <= 1) {
        return 1;
    }
    if (N > M) {
        return calculate(M, M);
    }
    return calculate(M, N - 1) + calculate(M - N, N);
}

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        int M, N;
        cin >> M >> N;
        cout << calculate(M, N) << endl;
    }
    return 0;
}