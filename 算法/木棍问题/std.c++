#include <bits/stdc++.h>
using namespace std;

bool DFS(int cnt, int len, int pos, int target, vector<int>& input, vector<bool>& book) {
    if (cnt == 0) {
        return true;
    }
    if (len == target) {
        return DFS(cnt - 1, 0, 0, target, input, book);
    }
    for (int i = pos; i < input.size(); i++) {
        if (book[i] && len + input[i] <= target) {
            book[i] = false;
            if (DFS(cnt, len + input[i], i + 1, target, input, book)) {
                return true;
            }
            book[i] = true;
            if (len == 0) {
                return false;
            }
            while (i + 1 < input.size() && input[i + 1] == input[i]) {
                i++;
            }
        }
    }
    return false;
}

int main() {
    int n, sum;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        sum = 0;
        vector<int> input(n);
        vector<bool> book(n, true);

        for (int i = 0; i < n; i++) {
            cin >> input[i];
            sum += input[i];
        }
        sort(input.begin(), input.end(), greater<int>());
        for (int target = input[0]; target <= sum; target++) {
            if (sum % target == 0) {
                int count = sum / target;
                if (DFS(count, 0, 0, target, input, book)) {
                    cout << target << endl;
                    break;
                }
            }
        }
    }
    return 0;
}