#include <bits/stdc++.h>
using namespace std;

struct Subans {
    int index;
    char left;
    char right;
    string subans;
};

int main() {
    int p1, p2, p3;
    string input;
    cin >> p1 >> p2 >> p3 >> input;
    bool flag = true;
    vector<Subans> targetlist;
    for (int i = 1; i < input.size() - 1; ++i) {
        if (input[i] == '-' && (('a' <= input[i - 1] && input[i - 1] < input[i + 1] && input[i + 1] <= 'z') || 
                                ('0' <= input[i - 1] && input[i - 1] < input[i + 1] && input[i + 1] <= '9'))) {
            Subans a;
            a.index = i;
            a.left = input[i - 1];
            a.right = input[i + 1];
            targetlist.push_back(a);
            flag = false;
        }
    }
    if (flag) {
        cout << input << endl;
        return 0;
    }
    for (int i = 0; i < targetlist.size(); ++i) {
        string s;
        if (targetlist[i].left + 1 == targetlist[i].right) {
            s = "";
        }
        else {
            for (int j = targetlist[i].left + 1; j < targetlist[i].right; ++j) {
                for (int k = 0; k < p2; ++k) {
                    s.push_back(j);
                }
            }
            if (p1 == 2 && targetlist[i].left >= 'a' && targetlist[i].right <= 'z') {
                for (int j = 0; j < s.size(); ++j) {
                    s[j] += 'A' - 'a';
                }
            }
            if (p1 == 3) {
                for (int j = 0; j < s.size(); ++j) {
                    s[j] = '*';
                }
            }
            if (p3 == 2) {
                reverse(s.begin(), s.end());
            }
        }
        targetlist[i].subans = s;
    }
    for (int i = 0; i < targetlist[0].index; ++i) {
        cout << input[i];
    }
    for (int i = 0; i < targetlist.size() - 1; ++i) {
        cout << targetlist[i].subans;
        for (int j = targetlist[i].index + 1; j < targetlist[i + 1].index; ++j) {
            cout << input[j];
        }
    }
    cout << targetlist[targetlist.size() - 1].subans;
    for (int i = targetlist[targetlist.size() - 1].index + 1; i < input.size(); ++i) {
        cout << input[i];
    }
    cout << endl;
}