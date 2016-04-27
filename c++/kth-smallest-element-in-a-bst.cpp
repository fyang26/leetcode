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
    int kthSmallest(TreeNode* root, int k) {
        int val;
        helper(root, k, val);
        return val;
    }
    
    void helper(TreeNode *root, int &k, int &val) {
        if (!root) return;
        helper(root->left, k, val);
        if (--k == 0) val = root->val;
        helper(root->right, k, val);
    }
};