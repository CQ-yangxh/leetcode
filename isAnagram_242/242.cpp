/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true

示例 2:
输入: s = "rat", t = "car"
输出: false
*/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++){
            record[s[i] - 'a']++;
        }
        // 可以优化成一个for循环
        for (int i = 0; i < t.size(); i++){
            record[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++){
            if (record[i] != 0) return false;
        }
        return true;
    }
};

int main (){
    string s = "anagram";
    string t = "nagaram";
    Solution sol;
    bool res = sol.isAnagram(s, t);
    return 0;
}