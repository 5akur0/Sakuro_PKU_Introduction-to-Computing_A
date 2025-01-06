// #include <bits/stdc++.h>
// using namespace std;

// namespace IO {
// template <typename T> inline void read(T &x) {
//     x = 0;
//     char c = getchar();
//     int f = false;
//     for (; !isdigit(c); c = getchar())
//         f |= c == '-';
//     for (; isdigit(c); c = getchar())
//         x = (x << 3) + (x << 1) + c - '0';
//     if (f)
//         x = -x;
// }
// template <typename T> inline void write(T x) {
//     if (x < 0)
//         putchar('-'), x = -x;
//     if (x >= 10)
//         write(x / 10);
//     putchar(x % 10 + '0');
// }
// } // namespace IO
// using namespace IO;

// const int INF = 1e9;

// int S[4][4];
// int d;
// int N;
// int dp[10005][10005] = { 0 };
// int a[10005], b[10005];

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
    
//     int M;
//     cin >> M;

//     for (int t = 1; t <= M; t++) {
//         for (int i = 0; i < 4; i++) {
//             for (int j = 0; j < 4; j++) {
//                 cin >> S[i][j];
//             }
//         }
//         cin >> d;
//         cin >> N;
//         cin.ignore();

//         cout << "Case #" << t << endl;

//         for (int i = 0; i < N; i++) {
//             string A, B;
//             cin >> A >> B;
//             int la = A.size();
//             int lb = B.size();
//             for (int j = 0; j < la; j++) {
//                 if (A[j] == 'A') {
//                     a[j] = 0;
//                 }
//                 else if (A[j] == 'G') {
//                     a[j] = 1;
//                 }
//                 else if (A[j] == 'C') {
//                     a[j] = 2;
//                 }
//                 else if (A[j] == 'T') {
//                     a[j] = 3;
//                 }
//             }
//             for (int j = 0; j < lb; j++) {
//                 if (B[j] == 'A') {
//                     b[j] = 0;
//                 }
//                 else if (B[j] == 'G') {
//                     b[j] = 1;
//                 }
//                 else if (B[j] == 'C') {
//                     b[j] = 2;
//                 }
//                 else if (B[j] == 'T') {
//                     b[j] = 3;
//                 }
//             }
//             dp[0][0] = 0;
//             for (int j = 1; j <= la + lb; ++j) {
//                 dp[j][0] = dp[j - 1][0] + d;
//                 dp[0][j] = dp[0][j - 1] + d;
//             }
//             for (int j = 2; j <= la + lb; j++) {
//                 for (int k = 1; k <= j - 1; k++) {
//                     dp[j - k][k] = max(dp[j - k][k], dp[j - 1 - k][k] + d);
//                     dp[j - k][k] = max(dp[j - k][k], dp[j - k][k - 1] + d);
//                     dp[j - k][k] = max(dp[j - k][k], dp[j - 1 - k][k - 1] + S[a[j - k - 1]][b[k - 1]]);
//                 }
//             }
//             cout << dp[la][lb] << endl;
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <string.h>
char s1[10000];
char s2[10000];
int dp[10000][10000];
int map[4][4];
int score(char x, char y) { 
    if (x == 'A' && y == 'A')
        return map[0][0];
    if (x == 'A' && y == 'G' || y == 'A' && x == 'G')
        return map[0][1];
    if (x == 'A' && y == 'C' || y == 'A' && x == 'C')
        return map[0][2];
    if (x == 'A' && y == 'T' || y == 'A' && x == 'T')
        return map[0][3];
    if (x == 'G' && y == 'G')
        return map[1][1];
    if (x == 'G' && y == 'C' || y == 'G' && x == 'C')
        return map[1][2];
    if (x == 'G' && y == 'T' || y == 'G' && x == 'T')
        return map[1][3];
    if (x == 'C' && y == 'C')
        return map[2][2];
    if (x == 'C' && y == 'T' || y == 'C' && x == 'T')
        return map[2][3];
    if (x == 'T' && y == 'T' || y == 'T' && x == 'T')
        return map[3][3];
}
int max(int a, int b, int c) {
    if (a >= b) {
        if (c >= a)
            return c;
        else
            return a;
    } else {
        if (c >= b)
            return c;
        else
            return b;
    }
}
int main(void) {
    int i, j, k, l, t, d, sum, n, w1, w2;
    int m;
    scanf("%d", &m);
    for (t = 1; t <= m; t++) {
        for (i = 0; i <= 3; i++)
            for (j = 0; j <= 3; j++)
                scanf("%d", &map[i][j]);
        scanf("%d", &d);
        scanf("%d", &n);
        printf("Case #%d\n", t);
        while (n--) {
            scanf("%s", s1);
            scanf("%s", s2);
            w1 = strlen(s1);
            w2 = strlen(s2);
            dp[0][0] = 0;
            for (i = 1; i <= w1; i++)
                dp[i][0] = i * d;
            for (i = 1; i <= w2; i++)
                dp[0][i] = i * d;
            for (i = 1; i <= w1; i++)
            {
                for (j = 1; j <= w2; j++)
                {
                    dp[i][j] =
                        max(dp[i - 1][j] + d,
                            dp[i - 1][j - 1] + score(s1[i - 1], s2[j - 1]),
                            dp[i][j - 1] + d);
                }
            }
            printf("%d\n", dp[w1][w2]);
        }
    }
    return 0;
}