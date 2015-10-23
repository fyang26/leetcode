class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int lo=0, hi=n-1;
        while (lo<=hi) {
            while (lo<n && nums[lo]!=val) lo++;
            while (hi>=0 && nums[hi]==val) hi--;
            if (lo<hi) swap(nums, lo++, hi--);
        }
        return hi+1;
    }
    
    void swap(vector<int> &nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};