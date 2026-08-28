class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        int res = INT_MAX;
        const int n = nums.size();
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for (int i = 0; i < n-1; i++)
            res = std::min(res, nums[i]-nums[i+1]);
        return res;
    }
};