#include <bits/stdc++.h>
using namespace std;

struct Char {
    char c;
    int n;
};

int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); ++i) {
        mp[s[i]]++;
    }
    vector<Char> data;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        Char C;
        C.c = it->first;
        C.n = it->second;
        data.push_back(C);
    }
    sort(data.begin(), data.end(), [](const Char &a, const Char &b){
        if (a.n > b.n) return true;
        if (a.n < b.n) return false;
        if (a.c <= b.c) return true;
        if (a.c > b.c) return false;
    });
    for (int i = 0; i < data.size(); ++i) {
        cout << data[i].c << " " << data[i].n << endl;
    }
    return 0;
}