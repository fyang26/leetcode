class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n==0) return res;
        dfs("", 0, 0, n, res);
        return res;
    }
    
    void dfs(string s, int left, int right, int n, vector<string> &res) {
        if (left>n) return;
        if (left==n && right==n) res.push_back(s);
        else {
            dfs(s+"(", left+1, right, n, res);
            if (left>right) dfs(s+")", left, right+1, n, res);
        }
    }
};