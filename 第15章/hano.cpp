#include <iostream>
using namespace std;

void hano(int n, char a, char b, char c) {
    if (n == 0) {
        return;
    }
    hano(n - 1, a, c, b);
    cout << a << "->" << c << endl;
    hano(n - 1, b, a, c);
}

int main() {
    int n;
    cin >> n;
    hano(n, 'A', 'B', 'C');
    return 0;
}