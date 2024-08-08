/*
给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。

示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
rabbbit
rabbbit
rabbbit

示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。
babgbag
babgbag
babgbag
babgbag
babgbag
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        // s中以i-1结尾的子序列中有多少个t中以j-1结尾的字符串
       vector<vector<uint64_t>> dp(s.size()+1, vector<uint64_t>(t.size()+1));
       for(int i = 0; i <= s.size(); i++) dp[i][0] = 1;
       for(int i = 1; i <= s.size(); i++)
        for(int j = 1; j <= t.size(); j++){
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
        return dp[s.size()][t.size()];
    }
};