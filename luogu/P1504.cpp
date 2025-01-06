#include <bits/stdc++.h>
using namespace std;

int n;
int input[105];
bool record[10005];
int Record[10005];
int now;
int max_sum = INT_MIN;


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        memset(record, false, sizeof(record));
        record[0] = true;
        int index = 0;
        int sum = 0;
        while (cin >> now) {
            if (now == -1) {
                break;
            }
            index++;
            input[index] = now;
            sum += now;
        }
        max_sum = max(sum, max_sum);
        for (int j = 1; j <= index; ++j) {
            for (int k = sum; k >= input[j]; --k) {
                if (record[k - input[j]] && !record[k]) {
                    record[k] = true;
                    Record[k]++;
                }
            }
        }
    }
    for (int i = max_sum; i >= 1; --i) {
        if (Record[i] >= n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}