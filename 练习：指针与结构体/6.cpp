#include <bits/stdc++.h>
using namespace std;

struct CacheLine {
    bool valid;
    unsigned int tag;
    int stamp;
};

int main() {
    int m, s, E;
    cin >> m >> s >> E;
    int n;
    cin >> n;

    int numGroups = 1 << s;
    vector<vector<CacheLine>> cache(numGroups,
                                    vector<CacheLine>(E, {false, 0, 0}));
    int counter = 0;
    int hits = 0, misses = 0, evictions = 0;

    for (int i = 0; i < n; ++i) {
        unsigned int addr;
        cin >> addr;

        unsigned int index = addr & ((1 << s) - 1);
        unsigned int tag = addr >> s;

        bool hit = false;
        for (int j = 0; j < E; ++j) {
            if (cache[index][j].valid && cache[index][j].tag == tag) {
                hit = true;
                cache[index][j].stamp = ++counter;
                hits++;
                break;
            }
        }

        if (!hit) {
            misses++;
            int minStamp = INT_MAX;
            int replaceIndex = -1;
            for (int j = 0; j < E; ++j) {
                if (!cache[index][j].valid) {
                    replaceIndex = j;
                    break;
                }
                if (cache[index][j].stamp < minStamp) {
                    minStamp = cache[index][j].stamp;
                    replaceIndex = j;
                }
            }
            if (cache[index][replaceIndex].valid) {
                evictions++;
            }
            cache[index][replaceIndex].valid = true;
            cache[index][replaceIndex].tag = tag;
            cache[index][replaceIndex].stamp = ++counter;
        }
    }

    cout << hits << " " << misses << " " << evictions << endl;
    return 0;
}

/*
代码说明：

索引计算：
unsigned int index = addr & ((1 << s) - 1);
这样可以获取地址 addr 的低 s 位，作为缓存的分组索引。

校验标记计算：
unsigned int tag = addr >> s;
通过右移 s 位，获取地址 addr 的高 m - s 位，作为校验标记。

测试样例验证：

以题目中的样例输入为例：
8 1 1
5
252
252
253
255
253
计算第一个地址 252：

addr = 252
index = 252 & ((1 << 1) - 1) = 252 & 1 = 0
tag = 252 >> 1 = 126
按照上述计算方式，程序应能得到正确的输出。

输出结果：
1 4 2

这样修改后，程序应当能够通过所有测试用例。
*/