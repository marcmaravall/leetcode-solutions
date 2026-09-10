class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int n = nums.size();
        int res = n;
        for (int i = 0; i < n-1; i++) {
            int num = nums[i];
            if (num != nums[i+1])
                continue;
            i++;
            for (i; i < n-1 && num == nums[i+1]; i++) {
                nums[i] = INT_MIN;
                res--;
            }
        }
        nums.erase(std::remove(nums.begin(), nums.end(), INT_MIN), nums.end());
        return res;
    }
};