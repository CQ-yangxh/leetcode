//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
    int searchInsert(vector<int>& nums, int target){
        int  left=0;
        int right=nums.size() - 1;
        if (target > nums[right]) return nums.size();
        if (target < nums[left]) return 0;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (target < nums[mid]){
                right = mid - 1;
            }
            else if (target > nums[mid]){
                left = mid + 1;
            }
            else return mid;
        }
        return left;
    }
};

int main(){
    vector<int> nums={1,3,5,6};
    int target = 7;
    Solution sol;
    int pos = sol.searchInsert(nums, target);
    return 0;
}