#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // dp数组的含义：
        // dp[i][0]：第i天持有股票的最大现金
        // dp[i][1]：第i天保持卖出股票的最大现金
        // dp[i][2]：第i天卖出股票的最大现金
        // dp[i][3]：冷冻期
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1] - prices[i], dp[i-1][3] - prices[i]));
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[n - 1][3], max(dp[n - 1][1], dp[n - 1][2]));
    }
};

int main(){


}