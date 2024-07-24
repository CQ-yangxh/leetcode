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
        res.push_back(cur->val);
        traversal(cur->right, res);
    }
    vector<int> inorderTraversal(TreeNode *root){
        vector<int> res;
        traversal(root, res);
        return res;
    }
    vector<int> inorderIter(TreeNode *root){
        // 14256
        // 中序遍历，左中右，一路向左入栈到底，栈顶的元素就是要操作的元素
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (!st.empty() || cur != nullptr){
            // 什么时候终止，栈没有元素了，且cur当前为空就结束了
            if (cur != nullptr){
                // 先一路向左访问节点
                st.push(cur);
                cur = cur->left;
            } else {
                // 到底了开始弹出栈顶的元素操作
                cur = st.top();
                res.push_back(cur->val);
                st.pop();
                cur = cur->right;
            }
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
    vector<int> res = sol.inorderTraversal(node1);
    return 0;
}