class Solution {
public:
    int rob(vector<int>& nums) {
        int m = nums.size();
        if (m==0) return 0;
        if (m==1) return nums[0];
        return max(helper(nums, 0, m-2), helper(nums, 1, m-1));
    }
    
    int helper(vector<int> &nums, int lo, int hi) {
        int cur = 0, prev = 0;
        for (int i=lo; i<=hi; i++) {
            int curtmp = max(nums[i]+prev, cur);
            prev = cur;
            cur = curtmp;
        }
        return cur;
    }
};