class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        const int n = nums1.size();
        std::sort(nums1.begin(), nums1.end());
        bool odd = false, even = false;
        // all odd
        for (int i = 0; i < n; i++) {
            if (even && odd)
                return true;
            if (nums1[i] % 2 == 0) {
                if (!odd)
                    break;
                even = true;
            }
            else odd = true;
        }
        // all even
        odd, even = false, false;
        for (int i = 0; i < n; i++) {
            if (even && odd)
                return true;
            if (nums1[i] % 2 == 1) {
                if (!odd)
                    return false;
                odd = true;
            }
            else even = true;
        }
        return true;
    }
};