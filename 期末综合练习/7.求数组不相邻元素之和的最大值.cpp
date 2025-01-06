#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    int yes = 0;
    int no = 0;
    int now;
    
    for (int _ = 0; _ < n; ++_) {
        cin >> now;
        if (now > 0) {
            swap(yes, no);
            no = max(yes, no);
            yes += now;
        }
        else {
            yes = max(yes, no);
            no = yes;
        }
    }
    cout << max(yes, no) << endl;
    return 0;
}