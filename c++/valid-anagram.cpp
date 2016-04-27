// Sort: time O(nlogn), space O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) return true;
        else return false;
    }
};

// Hash map: time O(n), space O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;
        for (auto &e : s)
            hash[e]++;
        for (auto &e : t) {
            if (hash.find(e) == hash.end()) return false;
            else {
                hash[e]--;
                if (hash[e] == 0) hash.erase(e);
            }
        }
        
        if (hash.empty()) return true;
        else return false;
    }
};

// array: time O(n), space O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int hash[26] = {0};
        for (auto &e : s) hash[e - 'a']++;
        for (auto &e : t) {
            if (hash[e-'a'] == 0) return false;
            else if (--hash[e-'a'] < 0) return false;
        }
        return true;
    }
};
