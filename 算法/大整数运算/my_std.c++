#include <bits/stdc++.h>
using namespace std;

// 简单的去除前导0的方式
void clearLeadingZeros(string &s){
    while (s.size() > 1 && s[0] == '0') {
        s.erase(s.begin());
    }
}

// 比较大小函数，保证减法输出正数
bool isLarger(string s1, string s2){
    if (s1.size() > s2.size()) {
        return true;
    }
    if (s1.size() < s2.size()) {
        return false;
    }
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] > s2[i]) {
            return true;
        }
        if (s1[i] < s2[i]) {
            return false;
        }
    }
    return true;
}

string largeAddition(string s1, string s2){
    if (s1.size() > s2.size()) {
        swap(s1, s2);
    }
    while (s1.size() < s2.size()) {
        s1 = '0' + s1;
    }
    // 我觉得reverse后做运算更便于理解
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result = "";
    int carry = 0;
    for (int i = 0; i < s1.size(); i++) {
        int temp = (s1[i] - '0') + (s2[i] - '0') + carry;
        carry = temp / 10;
        temp %= 10;
        result.push_back(temp + '0');
    }
    if (carry) {
        result.push_back(carry + '0');
    }
    reverse(result.begin(), result.end());
    clearLeadingZeros(result);
    return result;
}

// 保证了s1大于等于s2
string largeSubtraction(string s1, string s2){
    while (s1.size() > s2.size()) {
        s2 = '0' + s2;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    string result = "";
    int carry = 0;
    for (int i = 0; i < s1.size(); i++) {
        int temp = (s1[i] - '0') - (s2[i] - '0') - carry;
        if (temp < 0) {
            temp += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(temp + '0');
    }
    reverse(result.begin(), result.end());
    clearLeadingZeros(result);
    return result;
}

int main(){
    int n;
    cin >> n;
    string s1, s2;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        if (s1[0] == '+') {
            s1 = s1.substr(1);
        }
        if (s2[0] == '+') {
            s2 = s2.substr(1);
        }
        // 处理相同的情况防止输出“-0”
        if (s1 == s2) {
            cout << "0" << endl;
            continue;
        }
        // 一些枚举，可能臃肿但便于理解
        if (s1[0] != '-' && s2[0] == '-') {
            s2 = s2.substr(1);
            cout << largeAddition(s1, s2) << endl;
        } else if (s1[0] == '-' && s2[0] != '-') {
            s1 = s1.substr(1);
            cout << '-' << largeAddition(s1, s2) << endl;
        } else if (s1[0] == '-' && s2[0] == '-') {
            s1 = s1.substr(1);
            s2 = s2.substr(1);
            if (isLarger(s1, s2)) {
                cout << '-' << largeSubtraction(s1, s2) << endl;
            }
            else {
                cout << largeSubtraction(s2, s1) << endl;
            }
        } else {
            if (isLarger(s1, s2)) {
                cout << largeSubtraction(s1, s2) << endl;
            }
            else {
                cout << '-' << largeSubtraction(s2, s1) << endl;
            }
        }
    }
}