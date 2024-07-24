/*
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[3,2,1]
*/
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
public:
    void traversal(TreeNode *cur, vector<int> &res){
        if (cur == nullptr) return;
        traversal(cur->left, res);
        traversal(cur->right, res);
        res.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root){
        vector<int> res;
        traversal(root, res);
        return res;
    }
    vector<int> posterIter(TreeNode *root){
        // 12465
        vector<int> res;
        stack<TreeNode *> st;
        if(root == nullptr) return res;
        st.push(root);
        while (!st.empty()){
            TreeNode *cur = st.top();
            res.push_back(cur->val);
            st.pop();
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    TreeNode *node3 = new TreeNode(3, nullptr, nullptr);
    TreeNode *node2 = new TreeNode(2, node3, nullptr);
    TreeNode *node1 = new TreeNode(1, nullptr, node2);
    Solution sol;
    vector<int> res = sol.postorderTraversal(node1);
    return 0;
}