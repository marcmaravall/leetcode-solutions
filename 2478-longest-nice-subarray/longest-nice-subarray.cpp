class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        const int n = nums.size();
        int left = 0, right = 0;
        int freq[32] = {};
        auto put = [&](int x) {
            for (int i = 31; i >= 0; i--) {
                freq[i] += (x & (1 << i)) != 0;
            }
        };
        auto remove = [&](int x) {
            for (int i = 31; i >= 0; i--) {
                freq[i] -= (x & (1 << i)) != 0;
            }
        };
        auto nice = [&]() {
            for (int i = 0; i < 32; i++) {
                if (freq[i] > 1) {
                    return false;
                }
            }
            return true;
        };
        int res = 0;
        while (right < n) {
            if (left == right) {
                put(nums[right++]);
            } else if (!nice()) {
                remove(nums[left++]);
            } else {
                put(nums[right++]);
            }
            if (nice()) {
                res = std::max(res, right-left);
            }
        }
        return res;
    }
};