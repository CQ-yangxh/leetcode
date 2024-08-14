#include <iostream>
#include <string>
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

class Solution{
    void findPath(TreeNode* node, vector<int>& path, vector<string>& res){
        path.push_back(node->val);

        if(node->left == nullptr && node->right == nullptr){
            string pathStr;
            for(int i = 0; i < path.size() - 1; i++){
                pathStr += to_string(path[i]);
                pathStr += "->";
            }
            pathStr += to_string(*--path.end());
            res.push_back(pathStr);
            return;
        }

        if(node->left){
            findPath(node->left, path, res);
            path.pop_back();
        }

        if(node->right){
            findPath(node->right, path, res);
            path.pop_back();
        }

        return;
    }
    vector<string> binaryTreePaths(TreeNode *root){
        vector<int> path;
        vector<string> res;
        findPath(root, path, res);
        return res;
    }
};