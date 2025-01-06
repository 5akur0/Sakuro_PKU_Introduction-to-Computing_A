#include <bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int age;
    float score;
};

int main() {
    int N;
    cin >> N;
    vector<Student> students(N);
    for (int i = 0; i < N; ++i) {
        cin >> students[i].name >> students[i].age >> students[i].score;
    }

    sort(students.begin(), students.end(),
         [](const Student &a, const Student &b) {
             if (a.age != b.age) {
                 return a.age < b.age;
             } else if (a.score != b.score) {
                 return a.score > b.score;
             } else {
                 return a.name < b.name;
             }
         });

    while (students.size() > 10) {
        students.pop_back();
    }

    sort(students.begin(), students.end(),
                  [](const Student &a, const Student &b) {
                      return a.score > b.score;
                  });

    for (int i = 0; i < 10; ++i) {
        cout << students[i].name;
        if (i != 9) {
            cout << " ";
        } else {
            cout << endl;
        }
    }

    return 0;
}