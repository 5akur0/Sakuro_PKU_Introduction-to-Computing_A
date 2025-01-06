#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int hour, minute;
    for (int i = 0; i < T; ++i) {
        cin >> hour >> minute;
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
            cout << "Invalid input!" << endl;
            continue;
        }
        if ((hour >= 6 && hour <= 22) || (hour == 23 && minute == 0)) {
            cout << "Open." << endl;
        }
        else {
            cout << "Closed." << endl;
        }
    }
    return 0;
}