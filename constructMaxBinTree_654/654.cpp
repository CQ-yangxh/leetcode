class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;
        int maxid = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[maxid]) maxid = i;
        }
        TreeNode* root = new TreeNode(nums[maxid]);
        vector<int> leftnums(nums.begin(), nums.begin() + maxid);
        vector<int> rightnums(nums.begin() + maxid + 1, nums.end());
        root->left = constructMaximumBinaryTree(leftnums);
        root->right = constructMaximumBinaryTree(rightnums);
        return root;
    }
};