class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int m = 0;
        const int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            m = max(m, nums[i]);
            if (m > nums[i+2])
                return false;
        }
        return true;
    }
};