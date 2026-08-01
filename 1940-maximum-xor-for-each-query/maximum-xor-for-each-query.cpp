class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0;
        int p = 1 << maximumBit;
        const int n = nums.size();
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            x ^= nums[i];
            res[n-i-1] = p-x-1;
        }

        return res;
    }
};