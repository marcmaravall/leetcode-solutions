class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n <= 1)
            return n;
        std::vector<int> nums(n+1);
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; i+=2) {
            nums[i] = nums[i/2];
            if (i < n)
                nums[i+1] = nums[i/2]+nums[i/2+1];
        }
        return *std::max_element(nums.begin(), nums.end());
    }
};