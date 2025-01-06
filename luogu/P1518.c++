#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<bool> > map(10, vector<bool>(10, true));
    int x_Farmer, y_Farmer, x_Cow, y_Cow;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            char ch;
            cin >> ch;
            if (ch == 'C') {
                x_Cow = i;
                y_Cow = j;
            }
            else if (ch == 'F') {
                x_Farmer = i;
                y_Farmer = j;
            }
            else if (ch == '*') {
                map[i][j] = false;
            }
        }
    }
    int dir_Farmer = 0;
    int dir_Cow = 0;
    int counter = 0;
    while (true) {
        if (dir_Farmer == 0) {
            if (x_Farmer - 1 >= 0 && map[x_Farmer - 1][y_Farmer]) {
                x_Farmer--;
            } else {
                dir_Farmer = 1;
            }
        }
        else if (dir_Farmer == 1) {
            if (y_Farmer + 1 < 10 && map[x_Farmer][y_Farmer + 1]) {
                y_Farmer++;
            } else {
                dir_Farmer = 2;
            }
        }
        else if (dir_Farmer == 2) {
            if (x_Farmer + 1 < 10 && map[x_Farmer + 1][y_Farmer]) {
                x_Farmer++;
            } else {
                dir_Farmer = 3;
            }
        }
        else {
            if (y_Farmer - 1 >= 0 && map[x_Farmer][y_Farmer - 1]) {
                y_Farmer--;
            } else {
                dir_Farmer = 0;
            }
        }

        if (dir_Cow == 0) {
            if (x_Cow - 1 >= 0 && map[x_Cow - 1][y_Cow]) {
                x_Cow--;
            } else {
                dir_Cow = 1;
            }
        }
        else if (dir_Cow == 1) {
            if (y_Cow + 1 < 10 && map[x_Cow][y_Cow + 1]) {
                y_Cow++;
            } else {
                dir_Cow = 2;
            }
        }
        else if (dir_Cow == 2) {
            if (x_Cow + 1 < 10 && map[x_Cow + 1][y_Cow]) {
                x_Cow++;
            } else {
                dir_Cow = 3;
            }
        }
        else {
            if (y_Cow - 1 >= 0 && map[x_Cow][y_Cow - 1]) {
                y_Cow--;
            } else {
                dir_Cow = 0;
            }
        }
        
        counter++;

        if (x_Farmer == x_Cow && y_Farmer == y_Cow) {
            cout << counter << endl;
            return 0;
        }
        if (counter > 1000) {
            cout << 0 << endl;
            return 0;
        }          
    }
}