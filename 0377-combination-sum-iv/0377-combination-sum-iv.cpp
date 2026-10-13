class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int x : nums) {
                if (x <= i && dp[i - x] <= INT_MAX - dp[i])
                    dp[i] += dp[i - x];
                else if (x <= i)
                    dp[i] = INT_MAX;
            }
        }

        return dp[target];
    }
};