class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res = 2;
        const int n = nums.size();

        for (int i = 2; i < n; i++) {
            int current = 2;
            while (i < n && nums[i-2] + nums[i-1] == nums[i]) {
                current++;
                i++;
            }
        
            res = max(res, current);
        }

        return res;
    }
};