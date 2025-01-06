#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> MY(n);
        vector<int> OP(n);
        for (int i = 0; i < n; ++i) {
            cin >> MY[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> OP[i];
        }
        sort(MY.begin(), MY.end());
        sort(OP.begin(), OP.end()); //从小到大排序
        int ans = 0;
        //用双指针更佳，这里为了直观使用vector的两端删除
        while (MY.size() > 0) {
            if (MY.front() > OP.front()) {
                //如果自己最慢的比对手最慢的快，那么用自己最慢的赢对手最慢的
                MY.erase(MY.begin());
                OP.erase(OP.begin());
                ans++;
            }
            else if (MY.front() < OP.front()) {
                //如果自己最慢的比对手最慢的慢，那么用自己最慢的输对手最快的
                MY.erase(MY.begin());
                OP.pop_back();
                ans--;
            }
            else { //如果自己最慢的和对手最慢的一样
                if (MY.back() > OP.back()) {
                    //如果自己最快的比对手最快的快，那么用自己最快的赢对手最快的
                    MY.pop_back();
                    OP.pop_back();
                    ans++;
                }
                else {
                    /*
                    如果自己最快的比对手最快的慢，那么用自己最慢的输对手最快的；
                    如果最慢最快的都一样，那用自己最慢的输对手最快的，
                    因为至少可以再用自己最快的赢对手最慢的，相对于平局肯定不亏；
                    当然，这时也有可能是平局，所以要额外判断。
                    */
                    if (MY.front() < OP.back()) {
                        ans--;
                    }
                    MY.erase(MY.begin());
                    OP.pop_back();
                }
            }

        }
        cout << ans * 200 << endl;
    }
    return 0;
}