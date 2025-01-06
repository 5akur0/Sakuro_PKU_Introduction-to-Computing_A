#include <bits/stdc++.h>
using namespace std;

void DFS(int x, int y, string s, int n) {
    if (x < y) {
        return;
    }
    if (x > n || y > n) {
        return;
    }
    if (x == n && y == n) {
        cout << s << endl;
        return;
    }
    DFS(x + 1, y, s + "(", n);
    DFS(x, y + 1, s + ")", n);
}
int main() {
    int N;
    cin >> N;
    DFS(0, 0, "", N);
}