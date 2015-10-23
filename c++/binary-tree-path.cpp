/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str="";
        if (!root) return res;
        dfs(root, str, res);
        return res;
    }
    
    void dfs(TreeNode *root, string path, vector<string> &res) {
        if (!root) return;
        path = path + "->" + to_string(root->val);
        if (root->left || root->right) {
            dfs(root->left, path, res);
            dfs(root->right, path, res);
        } else res.push_back(path.substr(2));
    }
};