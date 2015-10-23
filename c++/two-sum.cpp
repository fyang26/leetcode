//hash map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            if (hash.find(target-nums[i]) != hash.end()) {
                res.push_back(min(i+1, hash[target-nums[i]]));
                res.push_back(max(i+1, hash[target-nums[i]]));
                return res;
            } else hash[nums[i]] = i+1;
        }
        return res;
    }
};


// sort
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> bk(nums);
        sort(nums.begin(), nums.end());
        vector<int> res;
        int lo=0, hi=nums.size()-1;
        int val1=-1, val2=-1;
        while (lo<hi) {
            if (nums[lo]+nums[hi]==target) {
                val1 = nums[lo];
                val2 = nums[hi];
                break;
            } else if (nums[lo]+nums[hi]<target) lo++;
            else hi--;
        }
        
        for (int i=0; i<nums.size(); i++) {
            if (bk[i]==val1 || bk[i]==val2) 
                res.push_back(i+1);
        }
        return res;
    }
};