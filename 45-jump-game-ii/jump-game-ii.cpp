class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n, 1000000);
        dp[n-1] = 0;
        for (int i = n-1; i >= 0; i--) {
            int maxJump = nums[i];
            for (int j = 0; j <= maxJump && i + j < n; j++) {
                dp[i] = min(dp[i+j] + 1, dp[i]);
            }
        }

        return dp[0];
    }
};