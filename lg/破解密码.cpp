#include <bits/stdc++.h>
using namespace std;

struct Move {
    int x;
    int y;
};

string decrypt(const string &enc, const string &encted) {
    string ret = "";
    string enctor = enc;
    while (enctor.size() < encted.size()) {
        enctor += enc;
    }
    for (int i = 0; i < encted.size(); ++i) {
        int x, y, z;
        if ('a' <= encted[i] && encted[i] <= 'z') {
            x = encted[i] - 'a';
        }
        else {
            x = encted[i] - 'A' + 26;
        }
        if ('a' <= enctor[i] && enctor[i] <= 'z') {
            y = enctor[i] - 'a';
        }
        else {
            y = enctor[i] - 'A' + 26;
        }
        z = x - y;
        if (z < 0) {
            z += 52;
        }
        if (z < 26) {
            ret += 'a' + z;
        }
        else {
            ret += 'A' + z - 26;
        }
    }
    return ret;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Move> moves(m);
    for (int i = 0; i < m; ++i) {
        cin >> moves[m - 1 - i].x >> moves[m - 1 - i].y;
    }
    vector<string> mystrings(n);
    for (int i = 0; i < n; ++i) {
        cin >> mystrings[i];
    }
    for (int i = 0; i < m; ++i) {
        mystrings[moves[i].y - 1] = decrypt(mystrings[moves[i].x - 1], mystrings[moves[i].y - 1]);
    }
    for (int i = 0; i < n; ++i) {
        cout << mystrings[i] << endl;
    }
    return 0;
}