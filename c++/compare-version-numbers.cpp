class Solution {
public:
    int compareVersion(string version1, string version2) {
        while (version1.length() && version2.length()) {
            int val1 = parse(version1), val2 = parse(version2);
            if (val1>val2) return 1;
            if (val1<val2) return -1;
        }
        
        while (version1.length())
            if (parse(version1)>0) return 1;
        while (version2.length())
            if (parse(version2)>0) return -1;
        
        return 0;
    }
    
    int parse(string &str) {
        int pos = str.find('.');
        int val = stoi(str.substr(0, pos));
        str = pos==string::npos?"":str.substr(pos+1);
        return val;
    }
};