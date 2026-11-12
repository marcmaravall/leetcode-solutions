class Solution {
public:
    int maximumGap(vector<int>& nums) {
        const int n = nums.size();
        if (n < 2) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            res = std::max(res, nums[i+1]-nums[i]);
        }
        return res;
    }
};