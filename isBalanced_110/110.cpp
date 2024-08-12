class Solution {
public:
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1) return -1;
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1) return -1;
        
        if(abs(rightHeight - leftHeight) > 1) return -1;
        else return max(rightHeight, leftHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int res = getHeight(root);
        if(res == -1) return false;
        else return true;
    }
};