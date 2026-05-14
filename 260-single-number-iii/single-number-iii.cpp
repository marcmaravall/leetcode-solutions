class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        std::vector<int> res;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i == n-1) {
                if (nums[i-1] != nums[i])
                    res.push_back(nums[i]);
            }
            else if (i == 0) {
                if (nums[i+1] != nums[i])
                    res.push_back(nums[i]);
            }
            else if (nums[i+1] != nums[i] && nums[i-1] != nums[i]) {
                res.push_back(nums[i]);
            }
        }

        return res;
    }
};