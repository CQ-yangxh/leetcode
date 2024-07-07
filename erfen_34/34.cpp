/*
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        bool flag = false;
        int mid;
        while (left <= right){
            mid = left + (right - left) / 2;
            if (target < nums[mid]){
                right = right - 1;
            }
            else if (target > nums[mid]){
                left = left + 1;
            }
            else{
                flag = true;
                break;
            }
        }
        if (flag){
            if (right == left) return {left, right};
            right = mid;
            left = mid;
            while (right <= nums.size() - 1 && nums[right] == target) right++; // 处理边界
            while (left >= 0 && nums[left] == target) left--;
            right = right - 1;
            left = left + 1; 
            return {left, right};
        }
        else return {-1, -1};
    }
};

int main(){
    vector<int> nums={2,2};
    int target = 2;
    Solution sol;
    vector<int> pos = sol.searchRange(nums, target);
    return 0;
}