class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        const int n = nums.size();
        int i = 1;
        std::vector<int> freq(52, 0);
        freq[nums[0]]++;
        for (i; i < n && nums[i] == nums[i-1]+1; i++) {
            sum += nums[i];
            freq[nums[i]]++;
        }
        for (i; i < n; i++)
            freq[nums[i]]++;
        int res = sum;
        if (res > 50)
            return res;
        while (freq[res] != 0)
            res++;
        return res;
    }
};