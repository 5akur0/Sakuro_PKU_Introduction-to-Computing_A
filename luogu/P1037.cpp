#include <bits/stdc++.h>
using namespace std;

string multiply(string num1, int num2)
{
    int carry = 0;
    string result = "";
    for (int i = num1.size() - 1; i >= 0; --i) {
        int product = (num1[i] - '0') * num2 + carry;
        result += (product % 10) + '0';
        carry = product / 10;
    }
    if (carry) {
        result += carry + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    string n;
    int k;
    cin >> n >> k;
    vector<pair<int, int>> moves;
    for (int i = 0; i < k; ++i) {
        pair<int, int> move;
        cin >> move.first >> move.second;
        if (move.second != 0 && move.first != move.second) {
            moves.push_back(move);
        }
    }
    vector<int> counts(10, 0);
    for (int j = 0; j < 10; ++j) {
        queue<int> q;
        set<int> visited;
        q.push(j);
        visited.insert(j);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (int i = 0; i < moves.size(); ++i) {
                if (cur == moves[i].first) {
                    int next = moves[i].second;
                    if (visited.find(next) == visited.end()) {
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }
        }
        counts[j] = visited.size();
    }

    string ans = "1";
    for (size_t i = 0; i < n.size(); ++i) {
        ans = multiply(ans, counts[n[i] - '0']);
    }
    cout << ans << endl;
    return 0;
}