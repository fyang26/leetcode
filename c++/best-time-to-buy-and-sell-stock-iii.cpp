class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> left(n+1, 0), right(n+1, 0);
        int minval = INT_MAX;
        for (int i=1; i<=n; i++) {
            left[i] = max(prices[i-1]-minval, left[i-1]);
            minval = min(minval, prices[i-1]);
        }
        int maxval = 0;
        for (int i=n-1; i>=0; i--) {
            right[i] = max(maxval-prices[i], right[i+1]);
            maxval = max(maxval, prices[i]);
        }
        
        int res = 0;
        for (int i=1; i<=n; i++){
            res = max(res, left[i]+right[i]);
        }
            
        return res;
    }
};