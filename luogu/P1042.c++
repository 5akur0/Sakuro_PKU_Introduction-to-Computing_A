#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch;
    vector<bool> input;
    while (cin >> ch) {
        if (ch == 'E') {
            break;
        }
        else if (ch == 'W') {
            input.push_back(true);
        }
        else if (ch == 'L') {
            input.push_back(false);
        }
    }
    // 11
    int scoreMe = 0;
    int scoreOp = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i]) {
            scoreMe++;
        }
        else {
            scoreOp++;
        }
        if (max(scoreMe, scoreOp) >= 11 && abs(scoreMe - scoreOp) >= 2) {
            cout << scoreMe << ":" << scoreOp << endl;
            scoreMe = 0;
            scoreOp = 0;
        }
    }
    cout << scoreMe << ":" << scoreOp << endl;
    cout << endl;

    // 21
    scoreMe = 0;
    scoreOp = 0;
    for (int i = 0; i < input.size(); ++i) {
        if (input[i]) {
            scoreMe++;
        }
        else {
            scoreOp++;
        }
        if (max(scoreMe, scoreOp) >= 21 && abs(scoreMe - scoreOp) >= 2) {
            cout << scoreMe << ":" << scoreOp << endl;
            scoreMe = 0;
            scoreOp = 0;
        }
    }
    cout << scoreMe << ":" << scoreOp << endl;
    return 0;
}