// 网易笔试.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;
int maxbenefit(int n, int sh_num, int sy_num, int hg_num, vector<vector<int>>& buildings) {
    vector<vector<int>> dp(sy_num + 1, vector<int>(hg_num+1, 0));
    vector<vector<int>> dpnext(sy_num + 1, vector<int>(hg_num+1, 0));
    for (int i = 0; i < n; ++i) {
        int ai = buildings[i][0], bi = buildings[i][1], ci=buildings[i][2], ui = buildings[i][3];
        for (int b=0; b<=sy_num; ++b)
            for (int c = 0; c <= hg_num; ++c) {
                dpnext[b][c] = max(dpnext[b][c], dp[b][c]);
                if (b >= bi && c >= ci) {
                    dpnext[b][c] = max(dpnext[b][c], dp[b - bi][c- ci] + ui);
                }
            }
        dp.swap(dpnext);
        fill(dpnext.begin(), dpnext.end(), vector<int>(hg_num + 1, 0));
    }
    return dp[sy_num][hg_num];
}
int main()
{
    int n, sh_num, sy_num, hg_num;
    cin >> n >> sh_num >> sy_num >> hg_num;
    vector<vector<int>> buildings(n, vector<int>(4));
    for (int i = 0; i < n; ++i)
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2] >> buildings[i][3];
    int maxbef = maxbenefit(n, sh_num, sy_num, hg_num, buildings);
    cout << maxbef << endl;
    return 0;
}