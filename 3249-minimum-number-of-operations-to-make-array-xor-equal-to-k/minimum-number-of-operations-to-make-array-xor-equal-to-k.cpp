class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = 0;
        for (int x : nums) {
            a ^= x;
        }
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            res += (a & mask) != (k & mask);
        }
        return res;
    }
};