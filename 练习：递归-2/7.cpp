#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> input(n);
    for (int i = 0; i < n; ++i) {
        cin >> input[i].second.first >> input[i].second.second >> input[i].first;
        for (int j = 0; j < i; ++j) {
            if (pow(input[i].second.first - input[j].second.first, 2) + 
                pow(input[i].second.second - input[j].second.second, 2) < 
                input[i].first + input[j].first) {
                    cout << "Yes" << endl;
                    return 0;
                }
        }
    }
    cout << "No" << endl;
    return 0;
}