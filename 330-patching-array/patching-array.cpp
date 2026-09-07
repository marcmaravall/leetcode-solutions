class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        const int s = nums.size();
        std::sort(nums.begin(), nums.end());
        long max = 0;
        int res = 0;
        int index = 0;
        while (max < n) {
            if (index < s && nums[index] <= max+1)
                max += nums[index++];
            else {
                max += max++;
                res++;
            }
        }
        return res;
    }
};