class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        long long left = 0, right = std::accumulate(nums.begin(), nums.end(), 0LL);
        long long min = INT64_MAX;
        for (int i = 0; i < n; i++) {
            left += nums[i];
            right -= nums[i];
            long long diff = i == n-1 ? left/n : std::abs((right/(n-i-1))-(left/(i+1)));
            if (diff < min) {
                min = diff;
                res = i;
            }
        }
        return res;
    }
};