class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i=0; i<input.length(); i++) {
            char c = input[i];
            if (c=='*' || c=='+' || c=='-') {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                int tmp = 0;
                for (auto &e:left) {
                    for (auto &f:right) {
                        if (input[i] == '+') tmp = e+f;
                        else if (input[i] == '-') tmp = e-f;
                        else tmp = e*f;
                        res.push_back(tmp);
                    }
                }
            }
        }
        return res.size()? res:vector<int>{stoi(input)};
    }
};