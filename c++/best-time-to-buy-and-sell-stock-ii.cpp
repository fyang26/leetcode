class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int maxdiff = 0;
        for (int i=0; i<prices.size()-1; i++) {
            maxdiff += max(0, prices[i+1] - prices[i]);
        }
        return maxdiff;
    }
};