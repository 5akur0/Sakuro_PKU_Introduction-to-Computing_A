#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int scores[4];
    int total;
};

int main() {
    Student students[5];
    int minTotal = INT_MAX;
    string minName;

    for (int i = 0; i < 5; ++i) {
        cin >> students[i].name;
        students[i].total = 0;
        for (int j = 0; j < 4; ++j) {
            cin >> students[i].scores[j];
            students[i].total += students[i].scores[j];
        }
        cout << students[i].name << " " << students[i].total << endl;
        if (students[i].total < minTotal) {
            minTotal = students[i].total;
            minName = students[i].name;
        }
    }
    cout << minName << " " << minTotal << endl;
    return 0;
}