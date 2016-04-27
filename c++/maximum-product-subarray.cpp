class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int m = nums.size();
        vector<int> dp(nums);
        int res = nums[0], minval = nums[0];
        for (int i=1; i<m; i++) {
            dp[i] = max(nums[i], max(nums[i]*dp[i-1], nums[i]*minval));
            minval = min(nums[i], min(nums[i]*dp[i-1], nums[i]*minval));
            res = max(res, dp[i]);
        }
        return res;
    }
};


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int m = nums.size();
        int res = nums[0], minval = nums[0], maxval = nums[0];
        for (int i=1; i<m; i++) {
            int prev = maxval;
            maxval = max(nums[i], max(nums[i]*prev, nums[i]*minval));
            minval = min(nums[i], min(nums[i]*prev, nums[i]*minval));
            res = max(res, maxval);
        }
        return res;
    }
};