#include <bits/stdc++.h>
using namespace std;

bool Contains(string s1, string s2) {
    if (s1.size() < s2.size()) {
        return false;
    }
    for (int i = 0; i < s2.size(); ++i) {
        if (s1[i] != s2[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> words;
    string word;
    while (cin >> word) {
        words.push_back(word);
    }
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << " ";
        bool f = true;
        for (int j = 1; j < words[i].size(); ++j) {
            string prefix = words[i].substr(0, j);
            bool flag = true;
            for (int k = 0; k < words.size(); ++k) {
                if (k == i) {
                    continue;
                }
                if (Contains(words[k], prefix)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << prefix << endl;
                f = false;
                break;
            }
        }
        if (f) {
            cout << words[i] << endl;
        }
    }
    return 0;
}