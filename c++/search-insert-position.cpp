class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos = 0;
        int n = nums.size(), lo = 0, hi = n-1;
        while (lo<hi) {
            int mid = lo+(hi-lo)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) lo = mid+1;
            else hi = mid - 1;
        }
        
        if (target>nums[lo]) return lo+1;
        else return lo;
    }
};