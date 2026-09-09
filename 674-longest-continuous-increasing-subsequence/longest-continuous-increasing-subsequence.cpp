class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1;
        const int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            int start = i;
            while (i < n-1 && nums[i] < nums[i+1])
                i++;
            res = std::max(res, i-start+1);
        }
        return res;
    }
};