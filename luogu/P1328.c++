#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> a_series(A);
    vector<int> b_series(B);
    for (int i = 0; i < A; ++i) {
        cin >> a_series[i];
    }
    for (int i = 0; i < B; ++i) {
        cin >> b_series[i];
    }
    int a_points = 0;
    int b_points = 0;
    int cur_a, cur_b;
    for (int i = 0; i < N; ++i) {
        cur_a = a_series[i % A];
        cur_b = b_series[i % B];
        if (cur_a != cur_b) {
            switch(cur_a) {
                case 0:
                    switch(cur_b) {
                        case 1:
                            b_points++;
                            break;
                        case 2:
                            a_points++;
                            break;
                        case 3:
                            a_points++;
                            break;
                        case 4:
                            b_points++;
                            break;
                    }
                    break;
                case 1:
                    switch(cur_b) {
                        case 0:
                            a_points++;
                            break;
                        case 2:
                            b_points++;
                            break;
                        case 3:
                            a_points++;
                            break;
                        case 4:
                            b_points++;
                            break;
                    }
                    break;
                case 2:
                    switch(cur_b) {
                        case 0:
                            b_points++;
                            break;
                        case 1:
                            a_points++;
                            break;
                        case 3:
                            b_points++;
                            break;
                        case 4:
                            a_points++;
                            break;
                    }
                    break;
                case 3:
                    switch(cur_b) {
                        case 0:
                            b_points++;
                            break;
                        case 1:
                            b_points++;
                            break;
                        case 2:
                            a_points++;
                            break;
                        case 4:
                            a_points++;
                            break;
                    }
                    break;
                case 4:
                    switch(cur_b) {
                        case 0:
                            a_points++;
                            break;
                        case 1:
                            a_points++;
                            break;
                        case 2:
                            b_points++;
                            break;
                        case 3:
                            b_points++;
                            break;
                    }
                    break;
            }
        }
    }
    cout << a_points << " " << b_points << endl;
}