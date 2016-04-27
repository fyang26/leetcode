class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comp;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, comp, res, 0);
        return res;
    }
    
    void dfs(vector<int>& candidates, int target, vector<int>& comp, vector<vector<int>> &res, int lo) {
        if (target==0) {
            res.push_back(comp);
            return;
        }
        int prev = -1;
        for (int i=lo; i<candidates.size(); i++) {
            if (prev != candidates[i]) {
                if (candidates[i]<=target) {
                    comp.push_back(candidates[i]);
                    dfs(candidates, target-candidates[i], comp, res, i);
                    comp.pop_back();
                }
                prev = candidates[i];
            }
        }
    }
};