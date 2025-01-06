#include <bits/stdc++.h>
using namespace std;

struct MyProb {
    int score;
    int time;
};

int main() {
    int M, N;
    cin >> M >> N;
    vector<MyProb> problems(M);
    char ch;
    for (int i = 0; i < M; ++i) {
        cin >> problems[i].score >> ch >> problems[i].time;
    }
    int time;
    int ans = -1;
    int I, T;
    int cur_ans;
    for (int i = 0; i < M; ++i) {
        int cur = i;
        cur_ans = 0;
        time = 0;
        while (cur < M && time + problems[cur].time <= N) {
            time += problems[cur].time;
            cur_ans += problems[cur].score;
            cur++;
        }
        if (cur_ans > ans) {
            ans = cur_ans;
            I = i + 1;
            T = time;
        }
        else if (cur_ans == ans && time < T) {
            I = i + 1;
            T = time;
        }
    }
    cout << I << ":" << ans << ";" << T << endl;
    return 0;
}