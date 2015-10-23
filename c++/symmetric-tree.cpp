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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        return issame(root->left, root->right);
    }
    
    bool issame(TreeNode *t1, TreeNode *t2) {
        if (!t1 && !t2) return true;
        else if (!t1 || !t2) return false;
        else return t1->val==t2->val && issame(t1->left, t2->right) && issame(t1->right, t2->left);
    }
};