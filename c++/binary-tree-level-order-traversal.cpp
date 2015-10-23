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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            int size = nodes.size();
            vector<int> comp;
            TreeNode *n;
            for (int i=0; i<size; i++) {
                n = nodes.front();
                comp.push_back(n->val);
                nodes.pop();
                if (n->left) nodes.push(n->left);
                if (n->right) nodes.push(n->right);
            }
            res.push_back(comp);
        }
        return res;
    }
};