#include <string>
using namespace std;

class Solution {
public:
    void reverse(string &s, int begin, int end){
        int left = begin;
        int right = end;
        while (left < right){
            swap(s[left++], s[right--]);
        }
    }
    void removeExtraSpaces(string &s){
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++){
            if(s[fast] != ' '){ // 遇到非空格才处理slow,所以后面的整个逻辑必须在if里面
                if(slow != 0) s[slow++] = ' '; // 手动添加空格
                while(fast < s.size() && s[fast] != ' '){
                    s[slow++] = s[fast++];
                }
            }
            // 这里还有一个fast++使fast指向空格
        }
        s.resize(slow);
    }
    string reverseWords(string s) {
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int cut = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){ // 注意到达字符串结尾这个条件不要漏掉
                reverse(s, cut, i-1);
                cut = i + 1;
            }
        }
        return s;
    }
};

int main(){
    string s = "  hello world  ";
    Solution sol;
    string res = sol.reverseWords(s);
    return 0;
}