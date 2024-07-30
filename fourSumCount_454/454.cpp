#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hmap;
        for (auto n1 : nums1) {
            for (auto n2 : nums2)
            {
                hmap[n1 + n2]++;
            }
        }

        int count = 0;
        for (auto n3 : nums3) {
            for (auto n4 : nums4) {
                if (hmap.find(0 - (n3 + n4)) != hmap.end()) {
                    count += hmap[0 - (n3 + n4)];
                }
            }
        }
        return count;
    }
};

int main() {
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { -2, -1};
    vector<int> nums3 = { -1, 2 };
    vector<int> nums4 = { 0, 2 };
    Solution sol;
    int res = sol.fourSumCount(nums1, nums2, nums3, nums4);
    return 0;
}