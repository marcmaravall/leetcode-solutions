class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size(), m = nums2.size();
        int res = 0;
        if (n % 2 == 1) {
            for (int x : nums2)
                res ^= x;
        }
        if (m % 2 == 1) {
            for (int x : nums1)
                res ^= x;
        }
        return res;
    }
};