class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        const int n = nums.size();
        int midFreq = 0;
        int mid = nums[n/2];
        for (int i = 0; i < n; i++) {
            if (nums[i] == mid) {
                if (++midFreq > 1)
                    return false;
            }
        }
        return true;
    }
};