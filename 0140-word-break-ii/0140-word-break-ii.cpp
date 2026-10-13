class Solution {
public:
    unordered_set<string> dict;
    vector<string> ans;

    void solve(string s, string path) {
        if (s.empty()) {
            path.pop_back();
            ans.push_back(path);
            return;
        }

        for (int i = 1; i <= s.size(); i++) {
            string word = s.substr(0, i);

            if (dict.count(word)) {
                solve(s.substr(i), path + word + " ");
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        solve(s, "");
        return ans;
    }
};