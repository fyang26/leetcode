// expand from center char
class Solution {
public:

    string longestPalindrome(string s) {
        int m = s.length();
        if (m<=1) return s;
        int minstart = 0, maxlen = 1;
        for (int i=0; i<m;) {
            if (m-i < maxlen/2) break;
            int lo = i, hi = i;
            while (hi<m-1 && s[hi]==s[hi+1]) hi++;
            i = hi+1;
            while (hi<m-1 && lo>0 && s[lo-1]==s[hi+1]) {
                hi++;
                lo--;
            }
            if (hi-lo+1 > maxlen) {
                maxlen = hi-lo+1;
                minstart = lo;
            }
        }
        return s.substr(minstart, maxlen);
    }
};


// dp
class Solution {
public:

    string longestPalindrome(string s) {
        int m = s.length();
        if (m<=1) return s;
        bool dp[1000][1000] = {false};
        int maxlen = 1, start = 0;
        for (int j=m-1; j>=0; j--) {
            for (int i=j; i<m; i++) {
                if ((i-j<2 || dp[j+1][i-1]) && s[i] == s[j]) {
                    dp[j][i] = true;
                    if (i-j+1 > maxlen) {
                        maxlen = i-j+1;
                        start = j;
                    }
                }
            }
            dp[j][j] = true;
        }
        return s.substr(start, maxlen);
    }
};