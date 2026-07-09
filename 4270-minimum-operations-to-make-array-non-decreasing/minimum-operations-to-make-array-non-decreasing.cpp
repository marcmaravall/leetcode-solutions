class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long res = 0;
        const int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            res += std::max(0, nums[i]-nums[i+1]);
        }

        return res;
    }
};