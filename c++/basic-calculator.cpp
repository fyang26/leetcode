class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        int res = 0;
        stack<char> op;
        stack<int> nums;
        int i=0;
        while (i<n) {
            int start = i;
            if (s[i]==' ') {i++; continue;}
            if (s[i]=='(' || s[i]=='+' || s[i]=='-') {op.push(s[i]); i++; continue;}
            if (s[i]==')' && !op.empty()) {
                op.pop();
                if (!op.empty() && nums.size()>1) {
                    int t = nums.top();
                    nums.pop();
                    if (op.top()=='+') t = nums.top() + t;
                    else t = nums.top() - t;
                    op.pop();
                    nums.pop(); 
                    nums.push(t);
                }
                i++;
                continue;
            }
            while (s[i]>='0' && s[i]<='9') i++;
            int t = stoi(s.substr(start, i-start));
            if (nums.empty()) nums.push(t);
            else {
                if (op.top()=='(') {nums.push(t); continue;}
                else if (op.top()=='+') t = nums.top() + t;
                else t = nums.top() - t;
                op.pop();
                nums.pop(); 
                nums.push(t);
            }
        } 
        return nums.top();
    }
};