class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        const int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }

        if (k % 2 == 1) {
            int minIndex = std::min_element(nums.begin(), nums.end()) - nums.begin();
            nums[minIndex] = -nums[minIndex];
        }

        return accumulate(nums.begin(), nums.end(), 0);
    }
};
