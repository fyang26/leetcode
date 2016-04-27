class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> myset;
        int m = s.length(), maxlen = 0, end = 0;
        for (int i=0; i<m; i++) {
            while (end<m && !myset.count(s[end]))
                myset.emplace(s[end++]);
            maxlen = max(maxlen, end-i);
            while (s[i] != s[end]) myset.erase(s[i++]);
            end++;
        }
        return maxlen;
    }
};