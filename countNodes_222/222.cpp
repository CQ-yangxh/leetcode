class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int leftcount = countNodes(root->left);
        int rightcount = countNodes(root->right);
        return leftcount + rightcount + 1;
    }
};