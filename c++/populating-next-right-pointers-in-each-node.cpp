/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeLinkNode *pre = q.front();
                q.pop();
                if (pre->left) q.push(pre->left);
                if (pre->right) q.push(pre->right);
                if (size) pre->next = q.front();
            }
        }
    }
};