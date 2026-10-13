class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int, unordered_set<int>> dp;

        for (int x : stones)
            dp[x] = {};

        dp[0].insert(0);

        for (int x : stones) {
            for (int jump : dp[x]) {
                for (int k = jump - 1; k <= jump + 1; k++) {
                    if (k > 0 && dp.count(x + k))
                        dp[x + k].insert(k);
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};