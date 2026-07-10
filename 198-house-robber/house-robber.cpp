class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        int a = nums[n-1], b = a, res = 0;
        if (n >= 2)
            b = std::max(nums[n-2], nums[n-1]);
        
        for (int i = n-3; i >= 0; i--) {
            int temp = a;
            a = b;
            b = std::max(nums[i] + temp, b);
        }
        
        return b;
    }
};