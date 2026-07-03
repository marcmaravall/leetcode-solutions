class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int m = 0;
        std::unordered_map<int, int> freq;
        for (int n : nums)
            m = max(m, ++freq[n%space]);
        int res = INT_MAX;
        for (int n : nums)
            if (freq[n % space] == m)
                res = std::min(res, n);
        return res;
    }
};