class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long left = 0, right = std::accumulate(nums.begin(), nums.end(), 0LL);
        const int n = nums.size();
        int res = 0;
        long long min = INT64_MAX;
        for (int i = 0; i < n; i++) {
            left += nums[i];
            right -= nums[i];
            long long diff = i == n-1 ? left/n : std::abs((right/(n-i-1))-(left/(i+1)));
            // std::cout << i << ": " << diff << "\n";
            if (diff < min) {
                min = diff;
                res = i;
            }
        }
        return res;
    }
};