#include <bits/stdc++.h>
using namespace std;

int romanToInt(const string& s)
{
    unordered_map<char, int> symbolOfValue = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
    int result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (i + 1 < s.size() && symbolOfValue[s[i]] < symbolOfValue[s[i + 1]]) {
            result -= symbolOfValue[s[i]];
        } else {
            result += symbolOfValue[s[i]];
        }
    }
    return result;
}

string intToRoman(int num)
{
    vector<pair<int, string>> symbolOfValue = {
        { 1000, "M" }, { 900, "CM" }, { 500, "D" }, { 400, "CD" },
        { 100, "C" }, { 90, "XC" }, { 50, "L" }, { 40, "XL" },
        { 10, "X" }, { 9, "IX" }, { 5, "V" }, { 4, "IV" }, { 1, "I" }
    };
    string result;
    for (const auto& [value, symbol] : symbolOfValue) {
        while (num >= value) {
            result += symbol;
            num -= value;
        }
    }
    return result;
}

int main()
{
    string input;
    cin >> input;
    if (isdigit(input[0])) {
        int num = stoi(input);
        cout << intToRoman(num) << endl;
    } else {
        cout << romanToInt(input) << endl;
    }
    return 0;
}