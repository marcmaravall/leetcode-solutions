class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0')
                    continue;
                dp[i][j] = 1;
                int a = (i == 0) ? 0 : dp[i-1][j];
                int b = (j == 0) ? 0 : dp[i][j-1];
                int c = (i == 0 || j == 0) ? 0 : dp[i-1][j-1];
                if (a > 0 && b > 0 && c > 0) {
                    dp[i][j] += std::min(std::min(a, b), c);
                }
                res = std::max(res, dp[i][j]);
                std::cout << dp[i][j] << " ";
            }
            std::cout << "\n";
        }
        return res*res;
    }
};