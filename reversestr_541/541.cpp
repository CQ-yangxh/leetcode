/*
给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例 1：
输入：s = "abcdefg", k = 2
输出："bacdfeg"
*/
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string reverse(string s) {
        int slow = 0;
        int fast = s.size() - 1;
        while (slow < fast) {
            swap(s[slow], s[fast]);
            slow++;
            fast--;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        int count = 0;
        string str;
        string last;
        while (s.size() - count >= 2*k){
            str = str + reverse(s.substr(count, k)) + s.substr(count+k, k);
            count = count + 2*k;
        }
        int remain = s.size() - count;
        if (remain < k)
            last = reverse(s.substr(count));
        if (k <= remain && remain < 2*k){
            last = reverse(s.substr(count, k)) + s.substr(count + k);
        }
        return (str + last);
    }
    string reverseStrSimple(string s, int k) {
        for(int i = 0; i < s.size(); i = i + 2*k){
            if (i + k <= s.size()) std::reverse(s.begin() + i, s.begin() + i + k);
            else std::reverse(s.begin()+i, s.end());
        }
        return s;
    }

};

int main(){
    string s = "abcdefg";
    int k = 2;
    Solution sol;
    string res = sol.reverseStrSimple(s, k);
    return 0;
}