#include <bits/stdc++.h>
using namespace std;

int countInversions(const string& s) {
    int inversions = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i + 1; j < s.size(); ++j) {
            if (s[i] > s[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<string, int>> input(m);

    for (int i = 0; i < m; ++i) {
        cin >> input[i].first;
        input[i].second = countInversions(input[i].first);
    }

    sort(input.begin(), input.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    for (const auto& dna : input) {
        cout << dna.first << endl;
    }

    return 0;
}