class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        std::array<int, 32> count {};
        for (int x : nums) {
            for (int i = 0; i < 32; i++) {
                count[i] += (x & (1 << i)) ? 1 : 0;
            }
        }
        int res = 0;
        constexpr int mod = 1e9+7;
        for (int j = 0; j < k; j++) {
            long long curr = 0;
            for (int i = 0; i < 32; i++) {
                if (count[i] > 0) {
                    count[i]--;
                    curr |= 1 << i;
                }
            }
            res = (res+curr*curr%mod)%mod;
        }
        return res;
    }
};