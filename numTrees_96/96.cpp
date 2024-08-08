#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // dp[i] 以1~i为节点的二叉搜索树的个数
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++)
            // 这个是根据找规律得出来的
                dp[i] += dp[j-1] * dp[i-j];
        }
        return dp[n];
    }
};