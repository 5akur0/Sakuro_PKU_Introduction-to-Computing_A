#include <bits/stdc++.h>
using namespace std;

int n, k;

// 判断一个数是否为质数
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0)
            return false;
    }
    return true;
}

// 深度优先搜索函数，选择 k 个数并计算其和
void dfs(const vector<int>& nums, int idx, int cnt, int sum, int& ans)
{
    if (cnt == k) {
        if (isPrime(sum)) {
            ++ans;
        }
        return;
    }
    for (int i = idx; i < n; ++i) {
        dfs(nums, i + 1, cnt + 1, sum + nums[i], ans);
    }
}

int main()
{
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    int ans = 0;
    dfs(nums, 0, 0, 0, ans);
    cout << ans << endl;
    return 0;
}