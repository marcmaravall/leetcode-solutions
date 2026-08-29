class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long res = 0;
        for (int& x : nums)
            x = std::abs(x);
        std::sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            res += i < n/2 ? -nums[i]*nums[i] : nums[i]*nums[i];
        }
        return res;
    }
};