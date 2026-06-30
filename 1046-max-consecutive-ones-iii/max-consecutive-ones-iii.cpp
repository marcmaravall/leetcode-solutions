class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        const int n = nums.size();
        for (i; i < n; i++) {
            if (nums[i] == 0)
                k--;
            if (k < 0 && nums[j++] == 0)
                k++;
        }
        return i-j;
    }
};