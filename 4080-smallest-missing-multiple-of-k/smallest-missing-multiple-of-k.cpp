class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        std::vector<int> freq(101);
        for (int x : nums)
            freq[x]++;
        int res = k;
        while (res < 101 && freq[res] > 0)
            res += k;
        return res;
    }
};