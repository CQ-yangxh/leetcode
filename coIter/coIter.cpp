#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int t) : val(t), left(nullptr), right(nullptr) {}
    TreeNode(int t, TreeNode* left, TreeNode* right) : val(t), left(left), right(right) {}
};

class Solution {
public:
    vector<int> midorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                // node 初始为中节点，因此要弹出
                st.pop();
                if (node->right) st.push(node->right);

                st.push(node);
                st.push(nullptr);

                if (node->left) st.push(node->left);
            }
            else {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
    vector<int> postorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.push(nullptr);

                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            }
            else {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
            }
        }
        return res;
    }
    vector<int> preorder(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            if (node != nullptr) {
                st.pop();

                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);

                st.push(node);
                st.push(nullptr);
            }
            else {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
            }

        }
        return res;
    }
};

int main() {
    TreeNode* node5 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(4, node5, node4);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* root = new TreeNode(5, node3, node2);
    Solution sol;
    //vector<int> res1 = sol.midorder(root);
     vector<int> res2 = sol.preorder(root);
     //vector<int> res3 = sol.postorder(root);
    return 0;
}