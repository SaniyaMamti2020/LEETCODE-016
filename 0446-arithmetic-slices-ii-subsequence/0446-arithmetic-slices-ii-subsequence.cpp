class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<unordered_map<long long,int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j];
                int cnt = dp[j][d];

                dp[i][d] += cnt + 1;
                ans += cnt;
            }
        }

        return ans;
    }
};