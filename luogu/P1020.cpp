#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100010;

int main() {
    vector<int> sequence;
    vector<int> ascendingSubseq(MAX_SIZE);
    vector<int> nonDecreasingSubseq(MAX_SIZE);

    int number;
    int length = 0, ascCount = 0, nonDescCount = 1;

    // 读取输入序列
    while (cin >> number) {
        sequence.push_back(number);

        if (ascCount == 0 || number <= ascendingSubseq[ascCount]) {
            ascCount++;
            ascendingSubseq[ascCount] = number;
        } else {
            int left = 1, right = ascCount;
            while (left < right) {
                int mid = (left + right) / 2;
                if (ascendingSubseq[mid] < number) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            ascendingSubseq[left] = number;
        }
    }

    // 输出最长非递增子序列的长度
    cout << ascCount << endl;

    if (!sequence.empty()) {
        nonDecreasingSubseq[1] = sequence[0];
    }

    // 构建最长非递减子序列
    for (size_t i = 1; i < sequence.size(); i++) {
        if (nonDecreasingSubseq[nonDescCount] < sequence[i]) {
            nonDescCount++;
            nonDecreasingSubseq[nonDescCount] = sequence[i];
        } else {
            int left = 1, right = nonDescCount;
            while (left < right) {
                int mid = (left + right) / 2;
                if (nonDecreasingSubseq[mid] >= sequence[i]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            nonDecreasingSubseq[left] = sequence[i];
        }
    }

    // 输出最长非递减子序列的长度
    cout << nonDescCount << endl;

    return 0;
}
