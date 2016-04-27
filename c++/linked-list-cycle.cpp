class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sums = 0, n = nums.size();
        for (auto &e: nums)
            sums += e;
        int all = (1+n)*n/2;
        return all - sums;
    }
};