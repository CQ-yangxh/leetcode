class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root;
        if(root1 == nullptr && root2 == nullptr)
            return nullptr;
        else if(root1 == nullptr){
            return root2;
        }
        else if(root2 == nullptr){
            return root1;
        }
        else{
            root = new TreeNode(root1->val + root2->val);
            root->left = mergeTrees(root1->left, root2->left);
            root->right = mergeTrees(root1->right, root2->right);
        }
        return root;
    }
};