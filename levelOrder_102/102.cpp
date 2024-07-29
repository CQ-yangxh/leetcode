#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right){}
};

class Solution {
    public:
    vector<vector<int>> levelOrder(TreeNode *root){
        queue<TreeNode*> que;
        if (root != nullptr) que.push(root);
        vector<vector<int>> res;
        while (!que.empty()){
            int size = que.size();
            vector<int> vec;
            for (int i = 0; i < size; i++){
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};

int main(){
    TreeNode *node5 = new TreeNode(7);
    TreeNode *node4 = new TreeNode(15);
    TreeNode *node3 = new TreeNode(20, node4, node5);
    TreeNode *node2 = new TreeNode(9);
    TreeNode *node1 = new TreeNode(3, node2, node3);
    Solution sol;
    vector<vector<int>> res = sol.levelOrder(node1);
    return 0;
}