#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        for(int i = 0; i < nums.size(); i++){
            que.push(nums[i]);
            if(que.size() > k)
                que.pop();
        }
        return que.top();
    }
};

int main(){
    vector<int> nums = {3,2,1,5,6,4};
    Solution sol;
    int res = sol.findKthLargest(nums, 2);
    return 0;
}