/*
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
返回你可以获得的最大乘积。

示例 1:
输入: n = 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。

示例 2:
输入: n = 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[2] = 1;
        for(int i = 3; i <= n; i++)
            for(int j = 1; j <= i/2; j++)
                dp[i] = max(dp[i], max(j*(i-j), j*dp[i-j]));
        return dp[n];
    }
};

int main(){
    int n = 2;
    Solution sol;
    int res = sol.integerBreak(n);
    return 0;
}