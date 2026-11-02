class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long res = INT_MAX;
        const int n = nums.size();
        long long left = 0, right = std::accumulate(nums.begin(), nums.end(), 0);
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            left += nums[i];
            long long cur = nums[i];
            res = std::min(res, right-cur*(n-i-1)+cur*i-left);
            right -= nums[i];
        }
        return res;
    }
};