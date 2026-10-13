class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        function<int(int,int)> dfs = [&](int r, int c) {
            if (dp[r][c]) return dp[r][c];

            int ans = 1;
            int dr[] = {1,-1,0,0};
            int dc[] = {0,0,1,-1};

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    matrix[nr][nc] > matrix[r][c])
                    ans = max(ans, 1 + dfs(nr, nc));
            }

            return dp[r][c] = ans;
        };

        int ans = 0;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, dfs(i, j));

        return ans;
    }
};