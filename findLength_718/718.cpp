/*
给两个整数数组 nums1 和 nums2 ，返回两个数组中公共的 、长度最长的子数组的长度。

示例 1：
输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。

示例 2：
输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
*/
#include <vector>
using namespace std;
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int res = 0;
        vector<vector<int>> dp(n1+1, vector<int>(n2 + 1, 0)); // 以i-1和j-1为结尾的最大公共子数组长度
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(nums1[i-1] == nums2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                if(dp[i][j] > res) res = dp[i][j];
            }
        }
        return res;
    }
};

int main(){

}