class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (s[i] == '+') ans.push_back(a + b);
                        else if (s[i] == '-') ans.push_back(a - b);
                        else ans.push_back(a * b);
                    }
                }
            }
        }

        if (ans.empty())
            ans.push_back(stoi(s));

        return ans;
    }
};