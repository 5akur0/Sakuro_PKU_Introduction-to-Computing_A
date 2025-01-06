#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> faces(n);
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> faces[i] >> names[i];
    }
    int cur = 0;
    int tmp_f;
    int tmp_num;
    for (int i = 0; i < m; ++i) {
        cin >> tmp_f >> tmp_num;
        if ((tmp_f + faces[cur]) % 2 == 0) {
            cur = (cur + n - tmp_num) % n;
        }
        else {
            cur = (cur + tmp_num) % n;
        }
    }
    cout << names[cur] << endl;
}