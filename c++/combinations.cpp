class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> sol;
        if (n<k) return res;
        dfs(n, k, 1, res, sol);
        return res;
        
    }
    
    void dfs(int n, int k, int start, vector<vector<int>> &res, vector<int> &sol) {
        if (sol.size() == k) {
            res.push_back(sol);
            return;
        }
        while (start<=n) {
            sol.push_back(start);
            dfs(n, k, ++start, res, sol);
            sol.pop_back();
        }
    }
};