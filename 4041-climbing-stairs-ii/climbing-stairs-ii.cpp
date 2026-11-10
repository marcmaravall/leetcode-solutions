class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        std::vector<int> dp(n+1, INT_MAX/2);
        dp[n] = 0;
        for (int i = n-1; i >= 0; i--) {
            if (i <= n-1) {
                dp[i] = std::min(dp[i], dp[i+1]+costs[i]+1);
            }
            if (i <= n-2) {
                dp[i] = std::min(dp[i], dp[i+2]+costs[i+1]+4);
            }
            if (i <= n-3) {
                dp[i] = std::min(dp[i], dp[i+3]+costs[i+2]+9);
            }
        }
        return dp[0];
    }
};