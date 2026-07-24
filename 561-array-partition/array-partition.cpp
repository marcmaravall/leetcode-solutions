class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const int s = nums.size();
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < s; i+=2) {
            res += nums[i];
        }
        return res;
    }
};