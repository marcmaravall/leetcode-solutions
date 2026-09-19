class Solution {
public:
    int maxLength(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long product = 1;
            long long lcm = 1;
            long long g = 0;
            for (int j = i; j < n; ++j) {
                product *= nums[j];
                g = std::gcd(g, (long long)nums[j]);
                lcm = lcm / std::gcd(lcm, (long long)nums[j]) * nums[j];
                if (product == g * lcm)
                    res = std::max(res, j - i + 1);
                if (product >= 2520*g*lcm) {
                    break;
                }
            }
        }
        return res;
    }
};
