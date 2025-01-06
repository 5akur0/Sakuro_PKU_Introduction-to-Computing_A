#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    unordered_map<int, int> remainder_position;
    int remainder = a % b;
    int position = 0;

    while (remainder != 0 && remainder_position.find(remainder) == remainder_position.end()) {
        remainder_position[remainder] = position;
        remainder = (remainder * 10) % b;
        position++;
    }

    if (remainder == 0) {
        cout << 0 << endl;
    } else {
        cout << position - remainder_position[remainder] << endl;
    }

    return 0;
}