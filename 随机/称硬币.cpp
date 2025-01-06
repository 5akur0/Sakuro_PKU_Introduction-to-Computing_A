#include <bits/stdc++.h>
using namespace std;

bool contains(const string &s, const char &c) {
    bool ret = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == c) {
            ret = true;
            break;
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    for (int _ = 0; _ < n; ++_) {
        vector<string> Left(3);
        vector<string> Right(3);
        vector<string> Comp(3);
        for (int i = 0; i < 3; ++i) {
            cin >> Left[i] >> Right[i] >> Comp[i];
        }
        for (int t = 0; t < 12; ++t) {
            char ch = 'A' + t;
            bool isLight = true;
            bool isHeavy = true;
            for (int i = 0; i < 3; ++i) {
                if (!contains(Left[i], ch) && !contains(Right[i], ch) && Comp[i] != "even") {
                    isLight = false;
                    isHeavy = false;
                } else if (contains(Left[i], ch) && Comp[i] != "up") {
                    isHeavy = false;
                } else if (contains(Left[i], ch) && Comp[i] != "down") {
                    isLight = false;
                } else if (contains(Right[i], ch) && Comp[i] != "up") {
                    isLight = false;
                } else if (contains(Right[i], ch) && Comp[i] != "down") {
                    isHeavy = false;
                }
            }
            if (isLight) {
                cout << ch << " is the counterfeit coin and it is light." << endl;
            }
            if (isHeavy) {
                cout << ch << " is the counterfeit coin and it is heavy." << endl;
            }
        }
    }
    return 0;
}