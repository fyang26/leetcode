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
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode *root, int cursum) {
        if (!root) return 0;
        if (!root->left && !root->right) return cursum*10 + root->val;
        else 
            return dfs(root->left, cursum*10+root->val) + dfs(root->right, cursum*10+root->val);
    }
};