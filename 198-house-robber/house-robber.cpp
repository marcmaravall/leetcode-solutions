class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        if (n >= 2)
            dp[n-2] = std::max(nums[n-2], nums[n-1]);
        for (int i = n-3; i >= 0; i--) {
            dp[i] = std::max(nums[i] + dp[i+2], dp[i+1]);
        }
        return dp[0];
    }
};