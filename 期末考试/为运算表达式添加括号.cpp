// AC CODE
#include <bits/stdc++.h>
using namespace std;

int numbers[18];
char operators[17];
int length = 1;
vector<pair<int, int>> dp[18][18];

int calculate(int a, int b, char op) {
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    default:
        return 0;
    }
}

int main() {
    cin >> numbers[length];
    while (cin >> operators[length] >> numbers[length + 1]) {
        length++;
    }

    for (int i = 1; i <= length; ++i) {
        dp[i][i].push_back(make_pair(numbers[i], 1));
    }

    for (int i = 1; i < length; ++i) {
        dp[i][i + 1].push_back(
            make_pair(calculate(numbers[i], numbers[i + 1], operators[i]), 1));
    }

    for (int d = 2; d <= length - 1; ++d) {
        for (int start = 1; start <= length - d; ++start) {
            int end = start + d;
            for (int i = start; i <= end - 1; ++i) {
                vector<pair<int, int>> left = dp[start][i];
                vector<pair<int, int>> right = dp[i + 1][end];
                for (const auto &l : left) {
                    for (const auto &r : right) {
                        int result = calculate(l.first, r.first, operators[i]);
                        bool found = false;
                        for (auto &entry : dp[start][end]) {
                            if (entry.first == result) {
                                entry.second += l.second * r.second;
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            dp[start][end].push_back(
                                make_pair(result, l.second * r.second));
                        }
                    }
                }
            }
        }
    }

    vector<pair<int, int>> results = dp[1][length];
    int count = 0;
    sort(results.begin(), results.end(),
         [](const pair<int, int> &a, const pair<int, int> &b) {
             return a.first < b.first;
         });

    for (const auto &result : results) {
        for (int j = 0; j < result.second; ++j) {
            cout << result.first << " ";
            count++;
            if (count >= 1000) {
                return 0;
            }
        }
    }

    return 0;
}

/*
// NAIVE DP
#include <bits/stdc++.h>
using namespace std;

int nums[20];
char op[20];
int length = 1;
vector<int> dp[20][20];

int calculate(int a, int b, char c) {
    if (c == '+') {
        return a + b;
    }
    if (c == '-') {
        return a - b;
    }
    if (c == '*') {
        return a * b;
    }
    return 0;
}

int main() {
    cin >> nums[length];
    while (cin >> op[length] >> nums[length + 1]) {
        length++;
    }

    for (int i = 1; i <= length; ++i) {
        dp[i][i].push_back(nums[i]);
    }

    for (int i = 1; i < length; ++i) {
        dp[i][i + 1].push_back(calculate(nums[i], nums[i + 1], op[i]));
    }

    for (int d = 2; d <= length - 1; ++d) {
        for (int start = 1; start <= length - d; ++start) {
            int end = start + d;
            for (int i = start; i <= end - 1; ++i) {
                vector<int> left = dp[start][i];
                vector<int> right = dp[i + 1][end];
                for (int x : left) {
                    for (int y : right) {
                        dp[start][end].push_back(calculate(x, y, op[i]));
                    }
                }
            }
        }
    }

    vector<int> results = dp[1][length];
    sort(results.begin(), results.end());
    int maxOutput = min(static_cast<int>(results.size()), 1000);

    for (int i = 0; i < maxOutput; ++i) {
        cout << results[i] << " ";
    }

    return 0;
}
*/

/*
//NAIVE DFS
#include <bits/stdc++.h>
using namespace std;

int nums[20];
char op[20];
int length = 1;

int calculate(int a, int b, char c) {
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    return 0;
}

vector<int> DFS(int l, int r) {
    vector<int> results;
    if (l == r) {
        results.push_back(nums[l]);
        return results;
    }
    if (l + 1 == r) {
        results.push_back(calculate(nums[l], nums[r], op[l]));
        return results;
    }
    for (int i = l; i <= r - 1; ++i) {
        vector<int> left = DFS(l, i);
        vector<int> right = DFS(i + 1, r);
        for (int x : left) {
            for (int y : right) {
                results.push_back(calculate(x, y, op[i]));
            }
        }
    }
    return results;
}

int main() {
    cin >> nums[length];
    while (cin >> op[length] >> nums[length + 1]) {
        length++;
    }
    vector<int> answers = DFS(1, length);
    sort(answers.begin(), answers.end());
    int maxOutput = min(static_cast<int>(answers.size()), 1000);
    for (int i = 0; i < maxOutput; ++i) {
        cout << answers[i] << " ";
    }
    return 0;
}
*/
