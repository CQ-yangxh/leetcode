#include <iostream>
#include <vector>
using namespace std;
void partitiion(vector<int>& nums, int& left, int& right){
    int pivot = nums[right];
    while (left < right){
        while (left < right && nums[left] >= pivot) left++;
        nums[right] = nums[left];
        while (left < right && nums[right] <= pivot) right--;
        nums[left] = nums[right];
    }
    nums[left] = pivot;
}
class Solution {
public:
    void minSubArrayLen(int limit, vector<int>& nums) {
        nums.push_back(limit);
        int left = 0;
        int right = nums.size()-1;
        partitiion(nums, left, right);

        for (int i = 0; i < left-1; i++){
            for (int j = i+1; j < left; j++){
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }
    }
};

int main()
{
    vector<int> test = {1,2,5,4,6};
    int limit = 3;
    Solution my_ans;
    my_ans.minSubArrayLen(limit, test);
    return 0;
}