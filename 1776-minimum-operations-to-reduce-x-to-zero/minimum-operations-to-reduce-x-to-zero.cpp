class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        const int n = nums.size();
        const int expected = total - x;
        int left = 0, right = 0, sum = 0;
        int res = INT_MAX;
        while (left < n || right < n) {
            if (left == right && right < n)
                sum += nums[right++];
            else if (sum < expected && right < n)
                sum += nums[right++];
            else sum -= nums[left++];
            if (sum == total - x)
                res = std::min(res, n - right + left);
        }
        return res == INT_MAX ? -1 : res;
    }
};