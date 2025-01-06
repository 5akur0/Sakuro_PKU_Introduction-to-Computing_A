#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int p, q;
    char c;
    cin >> p >> c >> q;
    bool flag = false;
    string input;
    stringstream oss;
    for (int i = p; i <= q; ++i) {
        input = to_string(i);
        reverse(input.begin(), input.end());
        int j = stoi(input);
        if (i <= j && j <= q && isPrime(i) && isPrime(j)) {
            oss << i << ',';
            flag = true;
        }
    }
    if (!flag) {
        cout << "NULL" << endl;
        return 0;
    }
    string output = oss.str();
    output.pop_back();
    cout << output << endl;
}