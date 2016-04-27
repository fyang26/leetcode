/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                vals.push(root->val);
                s.pop();
                root = root->right;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !vals.empty();
    }

    /** @return the next smallest number */
    int next() {
        int v = vals.front();
        vals.pop();
        return v;
    }
    
private:
    queue<int> vals;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */