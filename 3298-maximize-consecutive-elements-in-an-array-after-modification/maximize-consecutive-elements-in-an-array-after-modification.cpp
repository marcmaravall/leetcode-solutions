class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::unordered_map<int, int> dp;
        int res = 0;
        for (int x : nums) {
            dp[x+1] = std::max(dp[x+1], dp[x]+1);
            dp[x] = std::max(dp[x], dp[x-1]+1);
            res = std::max({res, dp[x], dp[x+1]});
        }
        return res;
    }
};