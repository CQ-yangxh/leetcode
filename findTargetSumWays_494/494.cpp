/*
给你一个非负整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：
输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) sum += nums[i];
        if(abs(target) > sum) return 0;
        if((target + sum) % 2 == 1) return 0;
        int sum1 = (target + sum) / 2;
        vector<int> dp(sum1);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++)
            for(int j = sum1; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        return dp[sum1];
    }
};

int main(){
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    Solution sol;
    int res = sol.findTargetSumWays(nums, target);
    return 0;
}