#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (str == "0") {
        cout << "0" << endl;
        return 0;
    }
    bool Neg = false;
    if (str[0] == '-') {
        Neg = true;
        str = str.substr(1);
    }
    reverse(str.begin(), str.end());
    while (str != "" && str[0] == '0') {
        str = str.substr(1);
    }
    if (Neg) {
        cout << "-";
    }
    cout << str << endl;
}
