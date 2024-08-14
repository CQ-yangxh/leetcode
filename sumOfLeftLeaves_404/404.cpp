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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 0;
        if(root->left && root->left->left == nullptr && root->left->right == nullptr) 
            return root->left->val + sumOfLeftLeaves(root->right);
        int leftsum = sumOfLeftLeaves(root->left);
        int rightsum = sumOfLeftLeaves(root->right);
        return leftsum + rightsum;
    }
};

int main(){
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(2, node4, node5);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node3, node2);
    Solution sol;
    int res = sol.sumOfLeftLeaves(root);
    return 0;
}