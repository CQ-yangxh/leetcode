/*
题目描述
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 

小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

输入描述
第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。

第二行包含 M 个正整数，代表每种研究材料的所占空间。 

第三行包含 M 个正整数，代表每种研究材料的价值。

输出描述
输出一个整数，代表小明能够携带的研究材料的最大价值。
输入示例
6 1
2 2 3 1 5 2
2 3 1 5 4 3
输出示例
5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> space(m);
    vector<int> value(m);
    for(int i = 0; i < m; i++) cin >> space[i];
    for(int i = 0; i < m; i++) cin >> value[i];
    
    vector<vector<int>> dp(m, vector<int>(n+1, 0));
    // 1. dp[i][j]表示什么：0-i种材料装进背包j中最大的价值
    // 2. dp[i][j] = max(dp[i-1][j], dp[i - 1][j - space[i]] + value[i])  放或者不放
    // 3.1 dp[0][j]: value[0] 和 j 当 j < value[0]时，dp[0][j] = 0
    // 3.2 dp[i][0]: dp[i][j] = 0;
    // 4. 遍历顺序，
    for(int j = value[0]; j <= n; j++)
        dp[0][j] = value[0];

    for(int i = 1; i < m; i++)
        for(int j = 1; j <= n; j++){
            if(j < space[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j - space[i]] + value[i]);
        }
    
    cout << dp[m-1][n] << endl;
    return 0;

}