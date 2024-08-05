#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int maxProfit_greedy(vector<int>& prices) {
        priority_queue<int, vector<int>, greater<int>> que;
        int i = 0;
        while(i < prices.size() - 1){
            int maxprofit = 0;
            int right = i + 1;
            if(prices[right] > prices[i]){
                while(right < prices.size() && prices[right] >= prices[right - 1])
                    right++;
                maxprofit = prices[right-1] - prices[i];
                que.push(maxprofit);
                if(que.size() > 2) que.pop();
                i = right;
            }
            else i++;
        }
        if(que.size() == 0) return 0;
        int val1 = que.top();
        if(que.size() == 1) return val1;
        que.pop();
        int val2 = que.top();
        return val1 + val2;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0]; // 第一次持有股票的现金
        dp[0][1] = 0; // 第一次不持有
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] + prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] - prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] + prices[i]);
        }
        return dp[n-1][3];
    }
};

int main(){
    vector<int> prices = {1,2,4,2,5,7,2,4,9,0};
    // 3 5 7
    Solution sol;
    int res = sol.maxProfit_greedy(prices);
    return 0;
}