class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            long long zeros = 0;
            while (i < n && nums[i] == 0) {
                zeros++;
                i++;
            }
            res += zeros*(zeros+1)/2;
        }
        return res;
    }
};