class Solution {
public:
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    void traversal(TreeNode* node){
        if(node == nullptr) return;
        traversal(node->left);
        if(pre != nullptr){
            res = min(res, abs(node->val - pre->val));
        }
        pre = node;
        traversal(node->right);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return res;
    }
};