#include <bits/stdc++.h>
using namespace std;

int DFS(int a, int b) {
    if (a == 1 && b == 1) {
        return 1;
    }
    if (a > b) {
        return 2 * DFS(a - b, b) + 1;
    }
    else {
        return 2 * DFS(a, b - a);
    }
}
int main() {
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << DFS(a, b) << endl;
    }
    return 0;
}