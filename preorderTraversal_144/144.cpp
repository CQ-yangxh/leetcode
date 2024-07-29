/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/
#include <vector>
#include <stack>
using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int t) : val(t), left(nullptr), right(nullptr) {}
    TreeNode(int t, TreeNode *left, TreeNode *right) : val(t), left(left), right(right) {}
};

class Solution {
public:
    void traversal(TreeNode *cur, vector<int> &vec){
        if (cur == nullptr) return;
        vec.push_back(cur->val);
        traversal(cur->left, vec);
        traversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> res;
        traversal(root, res);
        return res;
    }
    vector<int> posterIter(TreeNode *root){
        // 54126
        // 前序遍历，中左右，访问到中了就直接处理，然后要处理左，所以要使右先入栈，左后入栈
        vector<int> res;
        stack<TreeNode *> st;
        if(root == nullptr) return res;
        st.push(root);
        while (!st.empty()){
            TreeNode *cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return res;
    }
};

int main(){
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node2 = new TreeNode(2, node3, nullptr);
    TreeNode *root = new TreeNode(1, nullptr, node2);
    Solution sol;
    vector<int> res = sol.preorderTraversal(root);
    return 0;
}