class Solution {
public:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int> nums, int i) {
        const int n = nums.size();
        if (i >= n-1) {
            res.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++) {
            if (j != i && nums[i] == nums[j])
                continue;
            std::swap(nums[i], nums[j]);
            backtrack(res, nums, i+1);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
};