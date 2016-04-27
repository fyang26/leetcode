class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxdiff = 0, minval = prices[0];
        for (auto &e : prices) {
            maxdiff = max(maxdiff, e-minval);
            minval = min(minval, e);
        }
        return maxdiff;
    }
};