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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return dfs(nums, 0, nums.size()-1);
    }
    
    TreeNode *dfs(vector<int> &nums, int lo, int hi) {
        if (lo>hi) return NULL;
        int mid = lo+(hi-lo)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, lo, mid-1);
        root->right = dfs(nums, mid+1, hi);
        return root;
    }
};