class Solution {
public:
    int hIndex(vector<int>& citations) {
        if (citations.empty()) return 0;
        int m = citations.size(), lo =0, hi = m-1;
        int res = 0;
        while (lo<=hi) {
            int mid = lo+(hi-lo)/2;
            if (citations[mid]>=m-mid) {
                res = max(res, m-mid);
                hi = mid-1;
            } else lo = mid+1;
        }
        return res;
    }
};