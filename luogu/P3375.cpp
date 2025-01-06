#include <iostream>
#include <vector>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int m = pattern.size(), len = 0;
    vector<int> lps(m, 0);
    for (int i = 1; i < m;) {
        if (pattern[i] == pattern[len])
            lps[i++] = ++len;
        else if (len)
            len = lps[len - 1];
        else
            lps[i++] = 0;
    }
    return lps;
}

vector<int> kmpSearch(const string &text, const string &pattern) {
    vector<int> lps = computeLPS(pattern), matches;
    for (int i = 0, j = 0; i < text.size();) {
        if (text[i] == pattern[j])
            i++, j++;
        if (j == pattern.size())
            matches.push_back(i - j), j = lps[j - 1];
        else if (i < text.size() && text[i] != pattern[j])
            j ? j = lps[j - 1] : i++;
    }
    return matches;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;
    vector<int> result = kmpSearch(text, pattern);
    for (int i : result)
        cout << i << " ";
    return 0;
}