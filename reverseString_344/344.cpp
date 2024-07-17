/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char>::iterator front = s.begin();
        vector<char>::iterator back = s.end()-1;
        while(front < back){
        //需要注意的是，这里的循环条件是 front < back 而不是 front != back。这是因为在向量有偶数个元素时，front 和 back 不会相遇，
        //而在有奇数个元素时，它们会在中间元素处相遇。使用 front < back 可以确保不会对同一个元素进行两次不必要的交换。
            swap(*front, *back);
            front++;
            back--;
        }
    }
};

int main(){
    vector<char> s = {'h','e','l','l','o'};
    Solution sol;
    sol.reverseString(s);
    return 0;
}