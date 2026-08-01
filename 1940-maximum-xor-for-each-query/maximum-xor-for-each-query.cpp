class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        const int n = nums.size();
        std::vector<int> res(n);
        int x = 0;
        int p = 1 << maximumBit;
        for (int n : nums)
            x ^= n;
        for (int i = 0; i < n; i++) {
            res[i] = (p-1)-x;
            x ^= nums[n-i-1];
        }

        return res;
    }
};