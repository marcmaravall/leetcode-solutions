class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        std::unordered_map<int, long long> freq;
        for (int x : nums1) {
            freq[x] += m;
        }
        for (int x : nums2) {
            freq[x] += n;
        }
        int res = 0;
        for (const auto& [x, f] : freq) {
            if (f % 2 == 1) {
                res ^= x;
            }
        }
        return res;
    }
};