class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        unordered_set<int> hash;
        for (auto &e : nums) {
            if (hash.count(e)) return true;
            else hash.emplace(e);
        }
        return false;
    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};