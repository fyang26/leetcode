class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int cnt = 0;
                for (int x = max(0, i-1); x<=min(i+1, m-1); x++) {
                    for (int y = max(0, j-1); y<=min(j+1, n-1); y++) {
                        if (board[x][y] & 1) cnt++;
                    }
                }
                if (cnt == 3 || cnt-board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                board[i][j] >>= 1;
            }
        }
    }
};