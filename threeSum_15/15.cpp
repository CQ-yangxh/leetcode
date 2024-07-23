#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        sort(nums.begin(), nums.end(), greater<int>());
        for (int i = 0; i < nums.size() - 2; i++){
            int left = i+1;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                if (nums[i] + nums[left] + nums[right] <= 0) left++;
            }
        }
    }
};

int main(){

}