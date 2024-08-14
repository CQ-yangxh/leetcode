#include <iostream>
#include <string>
#include <vector>
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
    int traversal(TreeNode* node, vector<int> &path, int& targetSum){
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            int count = 0;
            for(auto& ele : path){
                count += ele;
            }
            return count;
        }
        if(node->left){
            int leftsearch = traversal(node->left, path, targetSum);
            if(leftsearch == targetSum) return leftsearch;
            path.pop_back();
        }
        if(node->right){
            int rightsearch = traversal(node->right, path, targetSum);
            if(rightsearch == targetSum) return rightsearch;
            path.pop_back();
        }
        return -1;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        vector<int> path;
        int res = traversal(root, path, targetSum);
        if(res == targetSum) return true;
        else return false;
    }
};

TreeNode* constructTree(const std::vector<int>& arr, int index) {
    if (index >= arr.size() || arr[index] == -1) {
        return nullptr;
    }

    TreeNode* node = new TreeNode(arr[index]);
    node->left = constructTree(arr, 2 * index + 1); // Left child
    node->right = constructTree(arr, 2 * index + 2); // Right child

    return node;
}

int main(){
    std::vector<int> nodes = {5, 4, 8, 11, -1, 13, 4, 7, 2, -1, -1, -1, -1, -1, 1};
    TreeNode* root = constructTree(nodes, 0);
    Solution sol;
    bool res = sol.hasPathSum(root, 22);
    return 0;
}