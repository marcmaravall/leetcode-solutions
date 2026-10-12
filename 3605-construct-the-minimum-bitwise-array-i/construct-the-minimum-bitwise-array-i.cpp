class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool found = false;
            for (int j = 0; j < nums[i]; j++) {
                if ((j | (j+1)) == nums[i]) {
                    nums[i] = j;
                    found = true;
                }
            }
            if (!found)
                nums[i] = -1;
        }
        return nums;
    }
};