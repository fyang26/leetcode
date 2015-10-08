class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int localmax = nums[0], res = localmax;
        int n = nums.size();
        for (int i=1; i<n; i++) {
            localmax = max(localmax, 0) + nums[i];
            res = max(res, localmax);
        }
        return res;
    }
};