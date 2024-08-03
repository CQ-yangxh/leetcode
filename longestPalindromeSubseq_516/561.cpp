/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for(int i = s.size() - 1; i >= 0; i--){
            for(int j = i+1; j < s.size(); j++){
                if(s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
                else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][s.size() - 1];
    }
    string tp_code(string s){
        int maxlength = 0;
        pair<int, int> res;
        int maxlen = 0;
        for(int i = 0; i < s.size(); i++){
            for(int j = s.size() - 1; j > i; j--)
            {
                int left = i;
                int right = j;
                while(left < right && s[left] == s[right]){
                        left++;
                        right--;
                }
                if(left >= right){
                    if(j - i + 1 > maxlen){
                        res.first = i;
                        res.second = j;
                        maxlen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(res.first, res.second - res.first + 1);
    }
};

int main(){
    string s = "bb";
    Solution sol;
    // int res = sol.longestPalindromeSubseq(s);
    string substr = sol.tp_code(s);
    return 0;
}