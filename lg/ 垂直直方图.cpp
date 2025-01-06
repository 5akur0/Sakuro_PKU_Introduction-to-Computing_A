#include <bits/stdc++.h>    
using namespace std;
vector<int> COUNTLIST(26, 0);

int main() {
    string line;
    for (int i = 0; i < 4; ++i) {
        getline(cin, line);
        for (int j = 0; j < line.size(); ++j) {
            if (line[j] >= 'A' && line[j] <= 'Z') {
                COUNTLIST[line[j] - 'A']++;
            }
    }
    
    }
    int maxCount = *max_element(COUNTLIST.begin(), COUNTLIST.end());
    for (int count = maxCount; count >= 1; --count) {
        cout << "# ";
        int maxId = 0;
        for (int i = 0; i < 26; ++i) {
            if (COUNTLIST[i] >= count) {
                maxId = i;
            }
        }
        for (int i = 0; i < maxId; ++i) {
            if (COUNTLIST[i] >= count) {
                cout << "* ";
            }
            else {
                cout << "  ";
            }
        }
        cout << "*" << endl;
    }
    cout << "# A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
}