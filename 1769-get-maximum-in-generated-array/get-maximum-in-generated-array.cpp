class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n < 2)
            return n;
        int nums[n+1];
        nums[0] = 0;
        nums[1] = 1;
        int res = 1;
        for (int i = 2; i <= n; i+=2) {
            nums[i] = nums[i/2];
            res = std::max(res, nums[i]);
            if (i < n) {
                nums[i+1] = nums[i/2]+nums[i/2+1];
                res = std::max(res, nums[i+1]);
            }
        }
        return res;
    }
};