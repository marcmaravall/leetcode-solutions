class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int res = 1;
        int m = nums[0];
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i]-m > k) {
                res++;
                m = nums[i];
            }
        }
        return res;
    }
};