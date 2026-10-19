class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left = 0, right = std::accumulate(nums.begin(), nums.end(), 0);
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            right -= nums[i];
            if (left == right)
                return i;
            left += nums[i];
        }
        return -1;
    }
};