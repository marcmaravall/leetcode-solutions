class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int left  = i != 0   ? nums[i-1] : INT_MIN;
            int right = i != n-1 ? nums[i+1] : INT_MIN;
            if (left < nums[i] && right < nums[i]) {
                return i;
            }
        }
        return 0;
    }
};