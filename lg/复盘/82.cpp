#include <bits/stdc++.h>
using namespace std;

int main() {
    cin >> noskipws;
    char ch;
    string word = "";
    map<string, int> mp;
    vector<string> words;
    while (cin >> ch) {
        if (isalpha(ch) || ch == '\'') {
            word += ch;
        }
        else if (word != "") {
            mp[word]++;
            if (mp[word] == 1) {
                words.push_back(word);
            }
            word = "";
        }
    }
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << " " << mp[words[i]] << endl;
    }
    return 0;
}