class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        std::vector<int> freq(51);
        for (int x : nums)
            freq[x]++;
        int res = -1;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (k == n || (freq[nums[i]] == 1 && (k==1 || !i || i==n-1)))
                res = std::max(res, nums[i]);
        }
        return res;
    }
};