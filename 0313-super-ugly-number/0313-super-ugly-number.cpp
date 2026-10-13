class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();

        vector<int> dp(n);
        vector<int> idx(k, 0);

        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            long long next = LLONG_MAX;

            for (int j = 0; j < k; j++) {
                next = min(next, 1LL * dp[idx[j]] * primes[j]);
            }

            dp[i] = (int)next;

            for (int j = 0; j < k; j++) {
                if (1LL * dp[idx[j]] * primes[j] == next)
                    idx[j]++;
            }
        }

        return dp[n - 1];
    }
};