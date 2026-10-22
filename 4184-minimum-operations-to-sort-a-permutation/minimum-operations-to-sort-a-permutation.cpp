class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int asc = 1, desc = 1;
        for (int i = 1; i < n; i++) {
            asc += nums[i] == (nums[i-1]+1)%n;
            desc += nums[i-1] == (nums[i]+1)%n;
        }
        if (asc == n) {
            return nums[0] ? std::min(n-nums[0], nums[0]+2) : 0;
        }
        if (desc == n) {
            return std::min(n-nums[n-1], nums[n-1])+1;
        }
        return -1;
    }
};