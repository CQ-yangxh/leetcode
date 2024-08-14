#include <iostream>
#include <string>
#include <vector>
#include <queue>
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* left;
        while(!que.empty()){
            int size = que.size();
            left = que.front();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return left->val;
    }
};