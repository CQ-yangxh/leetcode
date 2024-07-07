/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int> nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        int k = nums.size()-1;
        while (left <= right){
            if (nums[left]*nums[left] > nums[right]*nums[right]) {
                res[k--] = nums[left]*nums[left];
                left++;
            }
            else if (nums[left]*nums[left] <= nums[right]*nums[right]){
                res[k--] = nums[right]*nums[right];
                right--;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums={-5,-3,-2,-1};
    Solution sol;
    vector<int> res = sol.sortedSquares(nums);
    return 0;
}