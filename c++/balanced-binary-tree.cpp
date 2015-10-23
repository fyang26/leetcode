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
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int diff = abs(getdepth(root->left) - getdepth(root->right));
        if (diff>1) return false;
        else return isBalanced(root->left) && isBalanced(root->right);
    }
    
    int getdepth(TreeNode *root) {
        if (!root) return 0;
        return max(getdepth(root->left), getdepth(root->right)) + 1;
    }
};