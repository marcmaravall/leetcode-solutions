class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = 0;
        int mi = INT_MAX;
        for (int n : nums) {
            mx = std::max(mx, n);
            mi = std::min(mi, n);
        }
        return std::gcd(mx, mi);
    }
};