#include <bits/stdc++.h>
using namespace std;

vector<int> input;
int ans;
int M;
int l;

void DFS(int cur_sum, int cur_idx) {
    if (cur_sum == M) {
        ans++;
        return;
    }
    if (cur_idx == l) {
        return;
    }
    int c_idx = cur_idx;
    while (cur_sum + input[c_idx] > M) {
        c_idx++;
        if (c_idx == l) {
            return;
        }
    }
    DFS(cur_sum, c_idx + 1);
    DFS(cur_sum + input[c_idx], c_idx + 1);
}


int main() {
    string line;
    getline(cin, line);
    stringstream iss(line);
    int x;
    while (iss >> x) {
        input.push_back(x);
    }
    l = input.size();
    sort(input.begin(), input.end(), [](const int a, const int b){
        return a > b;
    });

    while (cin >> M) {
        if (M == 0) {
            break;
        }
        ans = 0;
        DFS(0, 0);
        cout << ans << endl;
    }
}