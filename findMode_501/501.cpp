#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){}
};
class Solution {
public:
    unordered_map<int, int> hmap;
    void traversal(TreeNode* cur){
        if(cur == nullptr) return;
        hmap[cur->val]++;
        traversal(cur->left);
        traversal(cur->right);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        int maxcount = 0;
        vector<int> res;
        res.push_back(maxcount);
        for(auto &pair : hmap){
            if(pair.second > maxcount){
                res.clear();
                res.push_back(pair.first);
                maxcount = pair.second;
            } 
            else if(pair.second == maxcount){
                res.push_back(pair.first);
            }
        }
        return res;
    }
};

TreeNode* constructTree(const std::vector<std::string>& arr, int index) {
    if (index >= arr.size() || arr[index] == "null") {
        return nullptr;
    }

    TreeNode* node = new TreeNode(std::stoi(arr[index]));
    node->left = constructTree(arr, 2 * index + 1); // Left child
    node->right = constructTree(arr, 2 * index + 2); // Right child

    return node;
}

int main(){
    vector<string> arr = {"1", "null", "2", "null", "null", "2", "null"};
    TreeNode* root = constructTree(arr, 0);
    Solution sol;
    vector<int> res = sol.findMode(root);
    return 0;
}