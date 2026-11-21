class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int res = 0;
        std::sort(nums.begin(), nums.end());
        if (k == 0) {
            for (int x : nums) {
                freq[x]++;
            }
            for (auto [n, f] : freq) {
                if (f > 1) {
                    res++;
                }
            }
            return res;
        }
        for (int x : nums) {
            if (freq[x]++ != 0) {
                continue;
            }
            res += (bool)freq[x-k];
        }
        return res;
    }
};