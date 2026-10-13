class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long sum = 0, f = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            f += 1LL * i * nums[i];
        }

        long long ans = f;

        for (int k = 1; k < n; k++) {
            f = f + sum - 1LL * n * nums[n - k];
            ans = max(ans, f);
        }

        return ans;
    }
};