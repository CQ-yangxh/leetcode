/*
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。

示例 1：
输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
*/
#include <vector>
using namespace std;
/* 迭代器的方法，速度慢
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fast = nums.begin()+1;
        while (fast < nums.end()){
            if (*slow == *fast){
                nums.erase(fast);
            }
            else {
                fast++;
                slow++;
            }
        }
        return nums.size();
    }
};
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        int n = nums.size();
        while (fast < n){
            if (nums[slow] != nums[fast]){
                slow++;
                nums[slow] = nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};

int main(){
    vector<int> nums{1,1,2,2,3};
    Solution sol;
    int res = sol.removeDuplicates(nums);
    return 0;
}