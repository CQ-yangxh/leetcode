class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        if(root->val == val) return root;
        TreeNode* res;
        if(root->val > val)
            res = searchBST(root->left, val);
        else
            res = searchBST(root->right, val);
        return res;
    }
};