/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:
输入: nums = [1], k = 1
输出: [1]
*/
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
    class mycmp{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++; // key value

    // 第一个参数元素类型，第二个参数是为元素提供一个容器
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycmp> pri_que;

    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++){
        pri_que.push(*it);
        if (pri_que.size() > k) pri_que.pop(); // 这里的pop是从堆顶pop
    }

    vector<int> res(k);
    for (int i = k - 1; i >= 0; i--){
        res[i] = pri_que.top().first;
        pri_que.pop();
    }

    return res;
    }
};

int main(){
    // int nums[] = {1,1,1,2,2,3}; // 注意数组的初始化
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    Solution sol;
    vector<int> res = sol.topKFrequent(nums, k);
    return 0;
}