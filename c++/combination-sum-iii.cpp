class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k>9 || k<1) return res;
        vector<int> comp;
        dfs(res, comp, k, n, 1);
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &comp, int k, int target, int start) {
        if (k==0 && target==0)
            res.push_back(comp);
        else if (k>0 && target!=0) {
            for (int i=start; i<=9; i++) {
                if (target-i>=0) {
                    comp.push_back(i);
                    dfs(res, comp, k-1, target-i, i+1);
                    comp.pop_back();
                }
            }
        }
    }
};