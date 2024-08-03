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
        int maxlen = 0;
        int start;
        for(int i = 0; i < n; i++){
            int left = i, right = i;
            // 单字节
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > maxlen){
                    maxlen = right - left +1;
                    start = left;
                }
                left--;
                right++;
            }

            // 双字节
            left = i;
            right = i+1;
            while(left >= 0 && right < n && s[left] == s[right]){
                if(right - left + 1 > maxlen){
                    maxlen = right - left +1;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start, maxlen);
    }
};

int main(){
    string s = "cbbd";
    Solution sol;
    string res = sol.longestPalindrome(s);
    return 0;
}