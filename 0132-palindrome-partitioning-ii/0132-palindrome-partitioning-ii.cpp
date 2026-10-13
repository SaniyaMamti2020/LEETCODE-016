class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) dp[i] = i;

        for (int i = 1; i < n; i++) {
            if (s[0] == s[i]) {
                int l = 0, r = i;
                bool pal = true;
                while (l < r)
                    if (s[l++] != s[r--]) pal = false;

                if (pal) dp[i] = 0;
            }

            for (int j = 1; j <= i; j++) {
                int l = j, r = i;
                bool pal = true;

                while (l < r)
                    if (s[l++] != s[r--]) pal = false;

                if (pal)
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }

        return dp[n - 1];
    }
};