class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        const int n = arr.size();
        std::vector<int> dp(n+1);
        for (int i = 1; i <= n; i++) {
            int m = 0, best = 0;
            for (int j = 1; j <= k && i-j >= 0; j++) {
                m = std::max(m, arr[i-j]);
                best = std::max(best, dp[i-j] + m*j);
            }

            dp[i] = best;
        }
        return dp[n];
    }
};