#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> matrix[i][j];
        }
    }

    int maxSum = INT_MIN;

    for (int left = 0; left < N; ++left) {
        vector<int> temp(N, 0);
        for (int right = left; right < N; ++right) {
            for (int i = 0; i < N; ++i) {
                temp[i] += matrix[i][right];
            }
            int currentSum = 0;
            for (int i = 0; i < N; ++i) {
                currentSum = max(temp[i], currentSum + temp[i]);
                maxSum = max(maxSum, currentSum);
            }
        }
    }

    cout << maxSum << endl;

    return 0;
}