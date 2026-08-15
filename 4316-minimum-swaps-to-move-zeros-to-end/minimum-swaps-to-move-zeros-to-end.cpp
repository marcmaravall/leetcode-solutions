class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        const int n = nums.size();
        int zeros = 0;
        for (int x : nums)
            zeros += x == 0;
        int res = 0;
        for (int i = n-1; i >= n-zeros; i--) {
            if (nums[i] != 0)
                res++;
        }
        return res;
    }
};