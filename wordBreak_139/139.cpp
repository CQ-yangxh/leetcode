#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int len = s.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        // for(int j = 1; j <= len; j++){ // 遍历背包
        //     for(int i = 0; i < j; i++){ // 遍历物品
        //     string word = s.substr(i, j-i);
        //         if(wordset.find(word) != wordset.end() && dp[i] == true) dp[j] = true;
        //     }
        //     for(auto ele : dp) cout << ele << " ";
        //     cout << endl;
        // }
        for(int i = 0; i < len; i++)
            for(int j = 1; j <= len; j++){
                string word = s.substr(i, j - i);
                if(wordset.find(word) != wordset.end() && dp[i] == true) dp[j] = true;
            }
        return dp[len];
    }
};

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    // string subs = s.substr(0, 1);
    // cout << subs << endl;
    Solution sol;
    bool res = sol.wordBreak(s, wordDict);
    return 0;
}