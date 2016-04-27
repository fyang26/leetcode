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
    void flatten(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;
        if (root->left && !root->right) {
            flatten(root->left);
            root->right = root->left;
            root->left = NULL;
        } else if (root->right && !root->left) 
            flatten(root->right);
        else {
            flatten(root->left);
            flatten(root->right);
            TreeNode *cur = root->left;
            while (cur && cur->right) cur = cur->right;
            if (cur) cur->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};