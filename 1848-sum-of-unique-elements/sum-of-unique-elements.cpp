class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int res = 0;
        const int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i == n-1)
                res += nums[i];
            else if (nums[i] != nums[i+1])
                res += nums[i];
            else while (i < n-1 && nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};