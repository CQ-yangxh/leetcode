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
    // dp数组（dp table）以及下标的含义：下标为0记录不偷该节点所得到的的最大金钱，下标为1记录偷该节点所得到的的最大金钱。
    vector<int> traversal(TreeNode *curnode){
        if(curnode == nullptr) return {0, 0};

        vector<int> left = traversal(curnode->left);
        vector<int> right = traversal(curnode->right);

        int val1 = curnode->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
    int rob(TreeNode* root) {
        vector<int> res = traversal(root);
        return max(res[0], res[1]);
    }
};