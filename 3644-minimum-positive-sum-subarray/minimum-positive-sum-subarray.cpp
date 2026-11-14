class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                int size = j-i+1;
                sum += nums[j];
                if (l <= size && size <= r && sum > 0) {
                    res = std::min(res, sum);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};