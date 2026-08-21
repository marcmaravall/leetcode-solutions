class Solution {
public:
    void dfs(std::vector<int> nums, int i, int j, std::vector<std::vector<int>>& res) {
        if (i == j-1) {
            res.push_back(nums);
            return;
        }
        for (int k = i ; k < j; k++) {
            if (i != k && nums[i] == nums[k])
                continue;
            std::swap(nums[i], nums[k]);
            dfs(nums, i+1, j, res);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res;
        dfs(nums, 0, nums.size(), res);
        return res;
    }
};