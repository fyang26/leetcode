class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        vector<vector<int>> res(grid);
        int row = grid.size(), col = grid[0].size();
        for (int i=1; i<row; i++)
            res[i][0] += res[i-1][0];
        for (int i=1; i<col; i++)
            res[0][i] += res[0][i-1];
            
        for (int i=1; i<row; i++) {
            for (int j=1; j<col; j++) {
                res[i][j] += min(res[i-1][j], res[i][j-1]);
            }
        }
        return res[row-1][col-1];
    }
};