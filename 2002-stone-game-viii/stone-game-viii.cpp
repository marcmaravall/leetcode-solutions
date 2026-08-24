class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        const int n = stones.size();
        std::vector<int> pref(n);
        pref[0] = stones[0];
        for (int i = 1; i < n; i++)
            pref[i] = stones[i]+pref[i-1];
        std::vector<int> dp(n);
        dp[n-1] = pref[n-1];
        for (int i = n-2; i >= 1; i--)
            dp[i] = std::max(dp[i+1], pref[i]-dp[i+1]);
        return dp[1];
    }
};