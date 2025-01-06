#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> A, B;
    string line;
    int num;
    char ch;
    getline(cin, line);
    stringstream ss(line);
    ss >> num;
    while (ss >> ch) {
        A.insert(num);
        ss >> num;
    }
    getline(cin, line);
    ss.clear();
    getline(cin, line);
    ss.str(line);
    ss >> num;
    while (ss >> ch) {
        B.insert(num);
        ss >> num;
    }
    set<int> C;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
    stringstream oss;
    for (auto it = C.begin(); it != C.end(); ++it) {
        oss << *it << ",";
    }
    string output = oss.str();
    output.pop_back();
    cout << output << endl;
}