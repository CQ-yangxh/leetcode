/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组是数组中的一个连续部分。
示例 1：
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray_greeady(vector<int>& nums) {
        int count = nums[0];
        int result = count;
        for (int i = 1; i < nums.size(); i++){
            if (count < 0) count = nums[i];
            else count = count + nums[i];
            if (result < count) {
                result = count; 
            }
        }
        return result;
    }
    int maxSubArray_dp(vector<int>& nums){
        // 这里i的定义：包括下标i（一定是以i结尾）的最大连续子序列和！！！
       vector<int> dp(nums.size()-1, 0);
       dp[0] = nums[0];
       int result = INT_MIN;
       for (int i = 1; i < nums.size(); i++){
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        if (result < dp[i]) result = dp[i];
       } 
       return result;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    int res1 = sol.maxSubArray_greeady(nums);
    int res2 = sol.maxSubArray_dp(nums);
    return 0;
}