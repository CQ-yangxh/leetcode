/*
编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

示例 1：
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getsum(int n){
        int sum = 0;
        while (n){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return  sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum = getsum(n);
            if (sum == 1) return true;
            if (set.find(sum) != set.end()) return false;
            else set.insert(sum);
            n = sum;
        }
    }
};

int main(){
    int n=19;
    Solution sol;
    bool res = sol.isHappy(n);
    return 0;
}