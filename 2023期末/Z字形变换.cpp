#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int n;
    cin >> s >> n;
    if (n == 1) {
        cout << s << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i += 2 * n - 2) {
        printf("%c", s[i]);
    }
    for (int j = 1; j < n - 1; ++j) {
        for (int i = j; i < s.size(); i += 2 * n - 2) {
            printf("%c", s[i]);
            if (i - 2 * j + 2 * n - 2 < s.size()) {
                printf("%c", s[i - 2 * j + 2 * n - 2]);
            }
        }
    }
    for (int i = n - 1; i < s.size(); i += 2 * n - 2) {
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}