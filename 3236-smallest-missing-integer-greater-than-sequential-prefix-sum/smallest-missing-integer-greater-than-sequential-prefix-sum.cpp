class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        const int n = nums.size();
        for (int i = 1; i < n && nums[i] == nums[i-1]+1; i++) {
            sum += nums[i];
        }
        std::unordered_map<int, int> freq;
        for (int x : nums)
            freq[x]++;
        int res = sum;
        while (freq[res] != 0)
            res++;
        return res;
    }
};