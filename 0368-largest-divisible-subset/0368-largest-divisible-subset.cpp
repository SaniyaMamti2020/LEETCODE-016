class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), best = 0, pos = 0;

        vector<int> dp(n, 1), parent(n, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }

            if (dp[i] > best) {
                best = dp[i];
                pos = i;
            }
        }

        vector<int> ans;

        while (pos != -1) {
            ans.push_back(nums[pos]);
            pos = parent[pos];
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};