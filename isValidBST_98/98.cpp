class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool left = isValidBST(root->left);
        if(pre != nullptr && pre->val >= root->val) return false;
        else pre = root;
        bool right = isValidBST(root->right);
        return left && right;
    }
};