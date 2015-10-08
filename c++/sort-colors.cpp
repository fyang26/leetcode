// counting sort

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[3] = {0};
        vector<int> res(nums);
        for (auto &e : nums)
            bucket[e]++;
        for (int i=1; i<3; i++)
            bucket[i] += bucket[i-1];
        for (int j=nums.size()-1; j>=0; j--) {
            res[bucket[nums[j]]-1] = nums[j];
            bucket[nums[j]]--;
        }
        nums = res;
    }
};