class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
            
        std::sort(nums.begin(), nums.end());
        int res = 1;
        const int n = nums.size();
        for (int i = 0; i < n-1; i++) {
            int len = 1;
            while (i < n-1 && nums[i]+1 == nums[i+1]) {
                len++;
                i++;
                while (i < n-1 && nums[i] == nums[i+1])
                    i++;
            }
            res = max(res, len);
        }

        return res;
    }
};