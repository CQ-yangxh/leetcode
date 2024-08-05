#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2, 0)));
        // dp数组的含义: dp[i][j][0/1] 第i天第j次持有/不持有股票的最大现金
        for(int i = 0; i < k; i++){
            dp[0][i][0] = -prices[0];
            dp[0][i][1] = 0;
        }
        for(int i = 1; i < n; i++){
            dp[i][0][0] = max(dp[i-1][0][0], -prices[i]);
            dp[i][0][1] = max(dp[i-1][0][1], dp[i-1][0][0] + prices[i]);
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < k; j++){
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j - 1][1] - prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j][0] + prices[i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++)
                cout << dp[i][j][0] << " " << dp[i][j][1] << "     ";
            cout << endl;
        }
        return dp[n-1][k-1][1];
    }
    int maxProfitII(int K, vector<int>& prices) {
        int n = prices.size();
        int dp[n][K + 1][2];
        // base case:
        for (int k = 0; k <= K; k++) {
            dp[0][k][0] = 0;
            dp[0][k][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1], dp[i - 1][0][0] - prices[i]);
        }
        // state transition:
        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= K; k++) {
                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] - prices[i]);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= K; j++)
                cout << dp[i][j][1] << " " << dp[i][j][0] << "     ";
            cout << endl;
        }
        return dp[n - 1][K][0];
    }
};

int main(){
    vector<int> nums = {2,1,4,5,2,9,7};
    Solution sol;
    int res = sol.maxProfit(2, nums);
    return 0;
}