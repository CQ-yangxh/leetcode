/*
给你一个字符串 s，找到 s 中最长的 回文子串。

示例 1：
输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。

示例 2：
输入：s = "cbbd"
输出："bb"
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 1;
        string res;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        if(n == 1) return s;
        // dp[i][j]表示从 i 到 j 最长的回文子串
        // dp[i][j] = dp[i + 1][j - 1] + 2
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                if(dp[i][j] > maxlen){
                    maxlen = dp[i][j];
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};

int main(){
    string s = "ac";
    Solution sol;
    string res = sol.longestPalindrome(s);
    return 0;
}