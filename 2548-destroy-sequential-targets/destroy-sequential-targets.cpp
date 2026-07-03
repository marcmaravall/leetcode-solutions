class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int res = INT_MAX;
        int m = 0;
        std::unordered_map<int, int> freq;
        
        for (int n : nums)
            m = std::max(m, ++freq[n % space]);
    
        for (int n : nums) {
            if (freq[n % space] == m)
                res = min(res, n);
        }
        return res;
    }
};