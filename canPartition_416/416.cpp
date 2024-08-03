/*
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
*/
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 如何与01背包对应起来
        // 每个元素的重量就是元素本身，每个元素的价值只要等于每个元素的重量就能判断背包有没有装满
        // dp[j]表示总和（这里为sum/2）为j的背包能够装的价值，当价值==总和时
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        int target = sum/2;
        int n = nums.size();
        vector<int> dp(target+1);
        for(int i = 0; i < n; i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
};

int main(){
    vector<int> nums = {1,2,3,5};
    Solution sol;
    bool res = sol.canPartition(nums);
    return 0;
}