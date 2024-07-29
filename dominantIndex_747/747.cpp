#include <vector>
using namespace std;
#include <map>
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        map<int, int, greater<int>> map;
        for(int i = 0; i < nums.size(); i++){
            int key = nums[i];
            map[key] = i;
        }
        int max = map.begin()->first;
        int submax = (++map.begin())->first;
        if (max >= 2*submax) return map.begin()->second;
        else return -1;
    }
};

int main(){
    vector<int> nums = {3, 6, 1, 0};
    Solution sol;
    int res = sol.dominantIndex(nums);
    return 0;
}