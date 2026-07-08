class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1;
        const int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1])
                continue;

            bool inc = nums[i-1] < nums[i];
            int current = 1;
            while (i < n && (inc ? (nums[i-1] < nums[i]) : (nums[i-1] > nums[i]))) {
                current++;
                i++;
            }
            i--;
            res = std::max(current, res);
        }
        return res;
    }
};