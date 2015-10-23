class Solution {
public:
    int lengthOfLastWord(string s) {
        if (!s.length()) return 0;
        int n = s.length();
        int res =0, i=n-1;
        for (; i>=0; i--) {
            if (s[i]!=' ') {
                res = i;
                while (i>=0 && s[i]!=' ') i--;
                break;
            }
        }
        if (i<0 && s[i+1]==' ') return 0;
        else return res-i;
    }
};