class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty()) return 0;
        return binarysearch(nums, 0, nums.size()-1);
    }
    
    int binarysearch(vector<int> &nums, int lo, int hi) {
        if (lo==0 && nums[lo]>nums[lo+1]) return lo;
        if (hi==nums.size()-1 && nums[hi]>nums[hi-1]) return hi;
        
        while (lo<hi) {
            int mid = lo+(hi-lo)/2;
            if (nums[mid] > nums[mid+1] && nums[mid]>nums[mid-1]) return mid;
            else if (nums[mid] > nums[mid+1]) hi = mid-1;
            else lo = mid+1;
        }
        return lo;
    }
};