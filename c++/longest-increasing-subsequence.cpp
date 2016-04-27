class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m = nums.size();
        if (!m) return 0;
        vector<int> dp(m, 1);
        int res = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<i; j++) {
                if (nums[j]<nums[i])
                    dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};