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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size() == 0) return nullptr;
        int rootval = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootval);
        if(postorder.size() == 1) return root;
        int index;
        // 找到分割点
        for(index = 0; index < inorder.size(); index++){
            if(inorder[index] == rootval) break;
        }
        // 左子树的中序遍历
        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        // 右子树的中序遍历
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        // 左子树的后序遍历
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + index);
        // 右子树的后序遍历
        vector<int> rightPostorder(postorder.begin() + index, postorder.end() - 1);
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);
        return root;
    } 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, postorder);
    }
};