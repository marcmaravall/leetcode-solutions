class Solution {
public:
    void backtrack(std::vector<int> nums, int i, std::vector<std::vector<int>>& res) {
        const int n = nums.size();
        if (i == n) {
            res.push_back(nums);
            return;
        }

        for (int k = i ; k < n; k++) {
            if (i != k && nums[i] == nums[k])
                continue;
            std::swap(nums[i], nums[k]);
            backtrack(nums, i+1, res);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        backtrack(nums, 0, res);
        return res;
    }
};