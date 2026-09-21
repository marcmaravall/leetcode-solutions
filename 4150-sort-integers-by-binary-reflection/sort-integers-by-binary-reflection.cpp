class Solution {
public:
    int reverse(int n) {
        int res = 0;
        while (n > 0) {
            res = (res << 1) | (n & 1);
            n >>= 1;
        }
        return res;
    }

    vector<int> sortByReflection(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            int ra = reverse(a);
            int rb = reverse(b);
            return ra != rb ? ra < rb : a < b;
        });
        return nums;
    }
};