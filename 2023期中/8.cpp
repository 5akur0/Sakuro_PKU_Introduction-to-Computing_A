#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<Point> points(n + 2);
        bool clockwise = true;
        int x_min = INT_MIN;
        int x_max = INT_MAX;
        int y_min = x_min;
        int y_max = x_max;
        for (int i = 0; i < n; ++i) {
            cin >> points[i].x >> points[i].y;
        }
        points[n] = points[0];
        points[n + 1] = points[1];
        int dx1, dy1, dx2, dy2;
        for (int i = 1; i < n + 1; ++i) {
            dx1 = points[i].x - points[i - 1].x;
            dy1 = points[i].y - points[i - 1].y;
            dx2 = points[i + 1].x - points[i].x;
            dy2 = points[i + 1].y - points[i].y;
            if (dx1 == 0) {
                if (dy1 > 0 && dx2 > 0) {
                    x_min = max(x_min, points[i].x);
                    y_max = min(y_max, points[i].y);
                }
                if (dy1 > 0 && dx2 < 0) {
                    x_min = max(x_min, points[i].x);
                    y_min = max(y_min, points[i].y);
                }
                if (dy1 < 0 && dx2 > 0) {
                    x_max = min(x_max, points[i].x);
                    y_max = min(y_max, points[i].y);
                }
                if (dy1 < 0 && dx2 < 0) {
                    x_max = min(x_max, points[i].x);
                    y_min = max(y_min, points[i].y);
                }
            }
            if (dy1 == 0) {
                if (dx1 > 0 && dy2 > 0) {
                    x_min = max(x_min, points[i].x);
                    y_max = min(y_max, points[i].y);
                }
                if (dx1 < 0 && dy2 > 0) {
                    x_min = max(x_min, points[i].x);
                    y_min = max(y_min, points[i].y);
                }
                if (dx1 > 0 && dy2 < 0) {
                    x_max = min(x_max, points[i].x);
                    y_max = min(y_max, points[i].y);
                }
                if (dx1 < 0 && dy2 < 0) {
                    x_max = min(x_max, points[i].x);
                    y_min = max(y_min, points[i].y);
                }
            }
        }
        if (x_max >= x_min && y_max >= y_min) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}