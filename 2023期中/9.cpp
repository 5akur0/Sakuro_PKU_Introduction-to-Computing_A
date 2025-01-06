#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> melody(N);
    for (int i = 0; i < N; ++i) {
        cin >> melody[i];
    }
    set<int> record;
    int ans = 1;
    for (int i = 0; i < N; ++i) {
        record.insert(melody[i]);
        if (record.size() >= M) {
            record.clear();
            ans++;
        }
    }
    cout << ans << endl;
}