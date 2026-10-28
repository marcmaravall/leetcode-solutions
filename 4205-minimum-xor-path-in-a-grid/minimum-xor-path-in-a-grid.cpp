class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(1024, -1)));
        auto dfs = [&](auto&& self, int i, int j, int temp) -> int {
            if (i >= n || j >= m) {
                return INT_MAX;
            }
            temp ^= grid[i][j];
            if (i == n-1 && j == m-1) {
                return temp;
            }
            if (dp[i][j][temp] != -1) {
                return dp[i][j][temp];
            }
            int down = self(self, i+1, j, temp);
            int right = self(self, i, j+1, temp);
            return dp[i][j][temp] = std::min(down, right);
        };

        return dfs(dfs, 0, 0, 0);
    }
};