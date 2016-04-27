class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, n = nums.size(), res = 0;
        for (int i=0; i<n-2; i++) {
            int val = nums[i];
            int lo=i+1, hi=n-1, curdiff;
            while (lo<hi) {
                int sums = nums[lo]+nums[hi]+val;
                curdiff = sums - target;
                if (abs(curdiff) < diff) {
                    diff = abs(curdiff);
                    res = sums;
                }
                if (curdiff == 0) return res;
                else if (curdiff > 0) hi--;
                else lo++;
                
            }
        }
        return res;
    }
};