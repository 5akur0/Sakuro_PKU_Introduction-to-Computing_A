// #include <bits/stdc++.h>
// using namespace std;

// int max_val, max_cnt, n, m;

// void DFS(vector<vector<int>> &Mat, int i, int cur_choice) {
//     // i：在处理第 i + 1 个邮票，last_val：前 i
//     // 个邮票达到的最大邮资，cur_choice：当前选择的邮票大小

//     for (int j = 0; j < Mat[i].size(); ++j) {
//         Mat[i][j] = -1;
//     }

//     Mat[i][0] = cur_choice;

//     int v = 0;

//     for (int j = 1;;++j) {
//         if (j % cur_choice == 0) {
//             Mat[i][j] = j / cur_choice;
//         } else {
//             if (Mat[i - 1][j % cur_choice] == -1) {
//                 Mat[i][j] = j / cur_choice + Mat[i][j % cur_choice];
//             } else if (Mat[i][j % cur_choice] == -1) {
//                 Mat[i][j] = j / cur_choice + Mat[i - 1][j % cur_choice];
//             } else {
//                 Mat[i][j] = j / cur_choice + 
//                             min(Mat[i - 1][j % cur_choice], Mat[i][j % cur_choice]);
//             }
//         }
//         if (Mat[i][j] > m) {
//             Mat[i][j] = -1;
//             v = j - 1;
//             break;
//         }
//     }
//     for (int t = 1; t <= m; ++t) {
//         Mat[i][cur_choice * t] = t;
//     }

//     if (i + 1 == n) {
//         if (v > max_val) {
//             max_val = v;
//             max_cnt = 1;
//         } else if (v == max_val) {
//             max_cnt++;
//         }
//         return;
//     }

//     int choice_min = cur_choice + 1;
//     int choice_max = v + 1;

//     for (int choice = choice_min; choice <= choice_max; ++choice) {
//         DFS(Mat, i + 1, choice);
//     }
// }

// int main() {
//     int k;
//     char ch;
//     cin >> k;
//     for (int _ = 0; _ < k; ++_) {
//         cin >> n >> ch >> m;
//         max_val = INT_MIN;
//         max_cnt = 0;
//         vector<vector<int>> Mat(n, vector<int>(pow(m + 1, n), -1));
//         // DP[i][0] 为 i + 1 个邮票大小， DP[i][j] 为邮票大小为前 i
//         // 个邮票，邮资为 j 的最小张数
//         Mat[0][0] = 1;
//         for (int j = 1; j <= m; ++j) {
//             Mat[0][j] = j;
//         }
//         for (int c = 2; c <= m + 1; ++c) {
//             DFS(Mat, 1, c);
//         }
//         cout << max_val << " " << max_cnt << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
pair<int, int> ans1[1005][1005];
int t, n, m;
int main() {
    cin >> t;
    ans1[1][1] = {1, 1};
    ans1[1][2] = {2, 1};
    ans1[1][3] = {3, 1};
    ans1[1][4] = {4, 1};
    ans1[1][5] = {5, 1};
    ans1[1][6] = {6, 1};
    ans1[1][7] = {7, 1};
    ans1[2][1] = {2, 1};
    ans1[2][2] = {4, 2};
    ans1[2][3] = {7, 1};
    ans1[2][4] = {10, 2};
    ans1[2][5] = {14, 1};
    ans1[2][6] = {18, 2};
    ans1[2][7] = {23, 1};
    ans1[3][1] = {3, 1};
    ans1[3][2] = {8, 1};
    ans1[3][3] = {15, 1};
    ans1[3][4] = {26, 1};
    ans1[3][5] = {35, 1};
    ans1[3][6] = {52, 1};
    ans1[3][7] = {69, 1};
    ans1[4][1] = {4, 1};
    ans1[4][2] = {12, 1};
    ans1[4][3] = {24, 1};
    ans1[4][4] = {44, 1};
    ans1[4][5] = {71, 2};
    ans1[4][6] = {114, 1};
    ans1[4][7] = {165, 1};
    ans1[5][1] = {5, 1};
    ans1[5][2] = {16, 1};
    ans1[5][3] = {36, 1};
    ans1[5][4] = {70, 1};
    ans1[5][5] = {126, 1};
    ans1[5][6] = {216, 1};
    ans1[6][1] = {6, 1};
    ans1[6][2] = {20, 1};
    ans1[6][3] = {52, 2};
    ans1[6][4] = {108, 2};
    ans1[7][1] = {7, 1};
    ans1[7][2] = {26, 3};
    ans1[7][3] = {70, 1};
    ans1[7][4] = {162, 3};
    ans1[8][1] = {8, 1};
    ans1[6][6] = {388, 1};
    ans1[8][2] = {32, 2};
    ans1[8][3] = {93, 1};
    ans1[9][1] = {9, 1};
    ans1[9][2] = {40, 1};
    ans1[10][1] = {10, 1};
    ans1[6][5] = {211, 2};
    ans1[10][2] = {46, 2};
    ans1[11][1] = {11, 1};
    ans1[11][2] = {54, 4};
    ans1[12][1] = {12, 1};
    ans1[12][2] = {64, 1};
    ans1[13][1] = {13, 1};
    ans1[14][1] = {14, 1};
    ans1[15][1] = {15, 1};
    ans1[16][1] = {16, 1};
    ans1[17][1] = {17, 1};
    ans1[18][1] = {18, 1};
    ans1[19][1] = {19, 1};
    ans1[20][1] = {20, 1};
    ans1[21][1] = {21, 1};
    ans1[22][1] = {22, 1};
    ans1[23][1] = {23, 1};
    ans1[24][1] = {24, 1};
    ans1[25][1] = {25, 1};
    ans1[26][1] = {26, 1};
    ans1[27][1] = {27, 1};
    ans1[28][1] = {28, 1};
    ans1[29][1] = {29, 1};
    ans1[30][1] = {30, 1};
    ans1[31][1] = {31, 1};
    ans1[32][1] = {32, 1};
    ans1[33][1] = {33, 1};
    ans1[34][1] = {34, 1};
    ans1[35][1] = {35, 1};
    ans1[36][1] = {36, 1};
    ans1[37][1] = {37, 1};
    ans1[38][1] = {38, 1};
    ans1[39][1] = {39, 1};
    ans1[40][1] = {40, 1};
    ans1[41][1] = {41, 1};
    ans1[42][1] = {42, 1};
    ans1[43][1] = {43, 1};
    ans1[44][1] = {44, 1};
    ans1[45][1] = {45, 1};
    ans1[46][1] = {46, 1};
    ans1[47][1] = {47, 1};
    ans1[48][1] = {48, 1};
    ans1[49][1] = {49, 1};
    ans1[50][1] = {50, 1};
    ans1[51][1] = {51, 1};
    ans1[52][1] = {52, 1};
    ans1[53][1] = {53, 1};
    ans1[54][1] = {54, 1};
    ans1[55][1] = {55, 1};
    ans1[56][1] = {56, 1};
    ans1[57][1] = {57, 1};
    ans1[58][1] = {58, 1};
    ans1[59][1] = {59, 1};
    ans1[60][1] = {60, 1};
    ans1[61][1] = {61, 1};
    ans1[62][1] = {62, 1};
    ans1[63][1] = {63, 1};
    ans1[64][1] = {64, 1};
    ans1[65][1] = {65, 1};
    ans1[66][1] = {66, 1};
    ans1[67][1] = {67, 1};
    ans1[68][1] = {68, 1};
    ans1[69][1] = {69, 1};
    ans1[70][1] = {70, 1};
    ans1[71][1] = {71, 1};
    ans1[72][1] = {72, 1};
    ans1[73][1] = {73, 1};
    ans1[74][1] = {74, 1};
    ans1[75][1] = {75, 1};
    ans1[76][1] = {76, 1};
    ans1[77][1] = {77, 1};
    ans1[78][1] = {78, 1};
    ans1[79][1] = {79, 1};
    ans1[80][1] = {80, 1};
    ans1[81][1] = {81, 1};
    ans1[82][1] = {82, 1};
    ans1[83][1] = {83, 1};
    ans1[84][1] = {84, 1};
    ans1[85][1] = {85, 1};
    ans1[86][1] = {86, 1};
    ans1[87][1] = {87, 1};
    ans1[88][1] = {88, 1};
    ans1[89][1] = {89, 1};
    ans1[90][1] = {90, 1};
    ans1[91][1] = {91, 1};
    ans1[92][1] = {92, 1};
    ans1[93][1] = {93, 1};
    ans1[94][1] = {94, 1};
    ans1[95][1] = {95, 1};
    ans1[96][1] = {96, 1};
    ans1[97][1] = {97, 1};
    ans1[98][1] = {98, 1};
    ans1[99][1] = {99, 1};
    while (t--) {
        scanf("%d,%d", &n, &m);
        // if(ans.count({n,m})) cout<<ans[{n,m}].first<<'
        // '<<ans[{n,m}].second<<endl;
        if (ans1[n][m].first)
            cout << ans1[n][m].first << ' ' << ans1[n][m].second << endl;
        else {
            cout << 0 << ' ' << 0 << endl;
        }
    }
    return 0;
}