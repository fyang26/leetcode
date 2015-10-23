class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int row=matrix.size(), col = matrix[0].size();
        int lo=0, hi=row-1;
        while (lo<hi) {
            int mid = (hi+lo)/2 + (hi+lo)%2;
            if (matrix[mid][0]==target) return true;
            else if (matrix[mid][0]<target) lo = mid;
            else hi = mid-1;
        }
        
        int collo=0, colhi=col-1;
        while (collo<colhi) {
            int mid = collo+(colhi-collo)/2;
            if (matrix[lo][mid]==target) return true;
            else if (matrix[lo][mid]<target) collo = mid+1;
            else colhi = mid-1;
        }
        if (matrix[lo][collo]==target) return true;
        return false;
        
    }
    
};