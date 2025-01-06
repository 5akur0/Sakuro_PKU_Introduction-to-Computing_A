#include <bits/stdc++.h>
using namespace std;

bool canAchieve24(vector<double>& numbers) {
        int n = numbers.size();
        if (n == 1) {
            return fabs(numbers[0] - 24) < 0.001;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                vector<double> nextNumbers;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        nextNumbers.push_back(numbers[k]);
                    }
                }
                double a = numbers[i];
                double b = numbers[j];
                nextNumbers.push_back(a + b);
                if (canAchieve24(nextNumbers)) {
                    return true;
                }
                nextNumbers.pop_back();
                nextNumbers.push_back(a - b);
                if (canAchieve24(nextNumbers)) {
                    return true;
                }
                nextNumbers.pop_back();
                nextNumbers.push_back(b - a);
                if (canAchieve24(nextNumbers)) {
                    return true;
                }
                nextNumbers.pop_back();
                nextNumbers.push_back(a * b);
                if (canAchieve24(nextNumbers)) {
                    return true;
                }
                nextNumbers.pop_back();
                if (b != 0) {
                    nextNumbers.push_back(a / b);
                    if (canAchieve24(nextNumbers)) {
                        return true;
                    }
                    nextNumbers.pop_back();
                }
                if (a != 0) {
                    nextNumbers.push_back(b / a);
                    if (canAchieve24(nextNumbers)) {
                        return true;
                    }
                    nextNumbers.pop_back();
                }
            }
        }
        return false;
}

int main() {
    vector<double> input(4);
    while (true) {
        cin >> input[0] >> input[1] >> input[2] >> input[3];
        if (input[0] == 0 && input[1] == 0 && input[2] == 0 && input[3] == 0) {
            break;
        }
        if (canAchieve24(input)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}