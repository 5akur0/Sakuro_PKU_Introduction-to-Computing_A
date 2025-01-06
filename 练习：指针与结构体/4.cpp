#include <bits/stdc++.h>
using namespace std;

struct Student {
    string id;
    string name;
    int score;
};

int main() {
    vector<Student> students;
    Student s;
    while (cin >> s.id >> s.name >> s.score) {
        if (s.score == 0) {
            break;
        }
        students.push_back(s);
    }
    sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.score > b.score;
    });
    // 12位学号
    for (const auto& student : students) {
        cout << student.id << "," << student.name << "," << student.score << endl;
    }
    return 0;
}