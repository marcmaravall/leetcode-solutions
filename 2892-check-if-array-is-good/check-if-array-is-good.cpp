class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return false;

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                return nums[i] == nums[i-1];
            } else if (nums[i] != i+1) {
                return false;
            }
        }
        return true;
    }
};