/*
题目描述
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。
这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 小明的行李空间为 N，问小明
应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

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
    int M, N;
    cin >> M >> N;
    vector<int> space(M), value(M);
    for(int i = 0; i < M; i++) cin >> space[i];
    for(int i = 0; i < M; i++) cin >> value[i];
    vector<int> dp(N+1);
    for(int i = 0; i < M; i++){
        for(int j = N; j >= space[i]; j--){
            dp[j] = max(dp[j], dp[j - space[i]] + value[i]);
        }
    }
    cout << dp[N];
    return 0;
}