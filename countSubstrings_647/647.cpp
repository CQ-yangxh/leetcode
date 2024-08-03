/*
给你一个字符串 s ，请你统计并返回这个字符串中回文子串的数目。
回文字符串是正着读和倒过来读一样的字符串。子字符串是字符串中的由连续字符组成的一个序列。

示例 1：
输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"

示例 2：
输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        // dp[i][j] 表示到从i到j是否是回文字符串
        int n = s.size();
        int count = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        // 递推公式：dp[i][j] = dp[i-1][j+1]
        for(int i = n - 1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(s[i] != s[j]) dp[i][j] = 0;
                else{
                    if(j - i <= 1){
                        count++;
                        dp[i][j] = 1;
                    }
                    else if(dp[i+1][j-1]){
                        count++;
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return count;
    }
};

int main(){
    string s = "aaa";
    Solution sol;
    int res = sol.countSubstrings(s);
    return 0;
}