class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 0;
        for (int i=0; i<8*sizeof(int); i++) {
            int cnt = 0;
            for (auto &e:nums)
                cnt += (e & (1<<i))==0?0:1;
            if (cnt % 3 != 0) res |= (1<<i);
        }
        return res;
    }
};