class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        if (nums.empty()) return res;
        dfs(nums, res, sol);
        return res;
    }
    
    void dfs(vector<int> &nums, vector<vector<int>> &res, vector<int> &sol) {
        if (nums.empty())
            res.push_back(sol);
        else {
            for (int i=0; i<nums.size(); i++) {
                int val = nums[i];
                sol.push_back(val);
                nums.erase(nums.begin()+i);
                dfs(nums, res, sol);
                nums.insert(nums.begin()+i, val);
                sol.pop_back();
            }
        }
    }
};