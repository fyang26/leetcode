class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int lo = 0, hi = n-1;
        while (lo<hi) {
            int mid = lo+(hi-lo)/2;
            if (nums[mid]<nums[max(0,mid-1)]) return nums[mid];
            else if (nums[mid]>nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
        return nums[lo];
    }
};