class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                int nonzero = i+1;
                while (nums[nonzero]==0) nonzero++;
                if (nonzero>=nums.size()) break;
                swap(nums, i, nonzero);
            }
        }
    }
    
    void swap(vector<int> &nums, int a, int b) {
        int t = nums[a];
        nums[a] = nums[b];
        nums[b] = t;
    }
};