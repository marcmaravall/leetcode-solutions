class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> prefixGcd(n);
        int mx = nums[0];
        for (int i = 0; i < n; i++) {
            mx = std::max(mx, nums[i]);
            prefixGcd[i] = std::gcd(nums[i], mx);
        }
        std::sort(prefixGcd.begin(), prefixGcd.end());
        long long res = 0;
        for (int i = 0; i < n/2; i++) {
            res += std::gcd(prefixGcd[i], prefixGcd[n-i-1]);
        }
        return res;
    }
};