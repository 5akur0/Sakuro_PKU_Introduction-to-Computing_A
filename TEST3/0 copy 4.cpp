#include <bits/stdc++.h>
using namespace std;

int main() {
    string red, blue;
    cin >> red >> blue;
    if (red.size() > blue.size()) {
        cout << "RED" << endl;
        return 0;
    }
    if (red.size() < blue.size()) {
        cout << "BLUE" << endl;
        return 0;
    }
    for (int i = 0; i < red.size(); ++i) {
        if (red[i] != blue[i]) {
            if (red[i] > blue[i]) {
                cout << "RED" << endl;
                return 0;
            }
            cout << "BLUE" << endl;
            return 0;
        }
    }
    cout << "EQUAL" << endl;
    return 0;
}