#include <bits/stdc++.h>
using namespace std;

int main() {
    char str1[201], str2[201];
    cin.getline(str1, 201);
    cin.getline(str2, 201);

    char *pos = nullptr;
    char *temp = strstr(str1, str2);

    while (temp != nullptr) {
        pos = temp;
        temp = strstr(temp + 1, str2);
    }

    if (pos == nullptr) {
        cout << -1 << endl;
    } else {
        cout << pos - str1 << endl;
    }

    return 0;
}