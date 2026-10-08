class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = INT_MAX, max = INT_MIN;
        for (int n : nums) {
            min = std::min(n, min);
            max = std::max(n, max);
        }
        return std::max(max-k-min-k, 0);
    }
};