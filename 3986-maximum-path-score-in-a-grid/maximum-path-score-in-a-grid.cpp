class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        std::vector<std::vector<int>> costs(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    continue;
                int cost = INT_MAX;

                if (i != 0)
                    cost = costs[i-1][j];
                if (j != 0)
                    cost = min(cost, costs[i][j-1]);

                costs[i][j] = cost + min(grid[i][j], 1);
            }
        }

        if (costs[n-1][m-1] > k)
            return -1;

        int costOf[3] = {0, 1, 1};
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(k+1, -1)));
        dp[0][0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    if (i+1 < n) {
                        int nc = c + costOf[grid[i+1][j]];
                        if (nc <= k)
                            dp[i+1][j][nc] = max(dp[i+1][j][nc], dp[i][j][c] + grid[i+1][j]);
                    }
                    if (j+1 < m) {
                        int nc = c + costOf[grid[i][j+1]];
                        if (nc <= k)
                            dp[i][j+1][nc] = max(dp[i][j+1][nc], dp[i][j][c] + grid[i][j+1]);
                    }
                }
            }
        }

        return *max_element(dp[n-1][m-1].begin(), dp[n-1][m-1].end());
    }
};