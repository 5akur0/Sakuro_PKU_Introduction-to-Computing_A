#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    int N = input.size();
    stringstream ss(input);
    int wordlencount = 0;
    vector<string> words;
    string word;
    while (ss >> word) {
        wordlencount += word.size();
        words.push_back(word);
    }
    if (words.size() == 1) {
        cout << words[0];
        for (int j = 0; j < N - wordlencount; ++j) {
            cout << " ";
        }
        cout << endl;
        return 0;
    }
    int k = (N - wordlencount) / (words.size() - 1);
    for (int i = 0; i < words.size() - 1; ++i) {
        cout << words[i];
        for (int j = 0; j < k; ++j) {
            cout << " ";
        }
    }   
    cout << words[words.size() - 1];
    for (int j = 0; j < (N - wordlencount) % (words.size() - 1); ++j) {
        cout << " ";
    }
    cout << endl;
    return 0;
}