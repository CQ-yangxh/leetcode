/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 5:
输入: "{[]}"
输出: true
*/
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int l = s.size();
        int i = 0;
        stack<char> st;
        while (i < l){
            if (st.empty()) {
                st.push(s[i]);
                i++;
                continue;
            }
            char jdg;
            switch (s[i]){
                case '}': jdg = '{'; break;
                case ')': jdg = '('; break;
                case ']': jdg = '['; break;
                default: jdg = ' ';
            }

            if (st.top() == jdg) st.pop();
            else st.push(s[i]);
            i++;
        }
        return st.empty();
    }
};

int main(){
    string s = "(){}}{";
    Solution sol;
    bool res = sol.isValid(s);
    return 0;
}