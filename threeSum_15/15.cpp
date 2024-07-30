#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 要将数组排序，才能够判断左右指针的移动方向
        sort(nums.begin(), nums.end(), less<int>());
        for (int i = 0; i < nums.size() - 2; i++){
            if(nums[i] > 0) return res; // 如果第一个元素大于0，则后面不可能存在三元组
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i+1;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // left和right的去重逻辑应该放在 = 0的分支里面，注意由于left和right是相向的，所以是right - 1 和 left + 1
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    while (left < right && nums[left] == nums[left + 1]) left++;

                    right--;
                    left++;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> res = sol.threeSum(nums);
    return 0;
}