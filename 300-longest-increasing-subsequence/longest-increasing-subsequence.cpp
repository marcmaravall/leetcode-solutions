class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> dp(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1;
                    res = std::max(res, dp[i]);
                }
            }
        }
        return ++res;
    }
};