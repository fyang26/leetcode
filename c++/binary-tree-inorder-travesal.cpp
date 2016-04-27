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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root==NULL) return res;
        stack<TreeNode*> nodes;
        while (!nodes.empty() || root!=NULL) {
            if (root) {
                nodes.push(root);
                root = root->left;
            } else {
                root = nodes.top();
                res.push_back(root->val);
                nodes.pop();
                root = root->right;
            }
        }
        return res;
    }
};