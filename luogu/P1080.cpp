#include <bits/stdc++.h>
using namespace std;

struct Person {
    int left;
    int right;
};

int main() {
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    vector<Person> people(n);
    for (int i = 0; i < n; ++i) {
        cin >> people[i].left >> people[i].right;
    }
    sort(people.begin(), people.end(), [](Person A, Person B){
        return A.left * A.right < B.left * B.right;
    });
    long long ans = 0;
    long long cur_mul = l;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, cur_mul / people[i].right);
        cur_mul *= people[i].left;
    }
    cout << ans << endl;
    return 0;
}