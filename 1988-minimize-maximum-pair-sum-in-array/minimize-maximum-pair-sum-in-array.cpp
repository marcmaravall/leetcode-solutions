class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            res = max(res, nums[i] + nums[n-i-1]);
        }

        return res;
    }
};