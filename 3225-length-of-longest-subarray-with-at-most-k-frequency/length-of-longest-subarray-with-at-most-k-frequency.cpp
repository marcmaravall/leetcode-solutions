class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int res = 0;
        const int n = nums.size();
        std::unordered_map<int, int> freq;
        while (left < n && right < n) {
            if (freq[nums[right]] >= k) {
                freq[nums[left++]]--;
                continue;
            }
            freq[nums[right++]]++;
            res = std::max(right-left, res);
        }
        return res;
    }
};