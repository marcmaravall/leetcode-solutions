class Solution {
public:
    int countConsistent(vector<int>& nums) {
        const int n = nums.size();
        int res = n;
        for (int i = 0; i < n; i++) {
            int min = nums[i];
            int val = nums[i];
            for (int j = i+1; j < n; j++) {
                val &= nums[j];
                min = std::min(min, nums[j]);
                if (val == min) {
                    res++;
                }
            }
        }
        return res;
    }
};