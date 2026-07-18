class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        const int n = nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<long long> prefix(n+1);
        for (int i = 0; i < n; i++) 
            prefix[i+1] = prefix[i]+nums[i];
        
        const int m = queries.size();
        std::vector<long long> res(m, 0);
        for (int i = 0; i < m; i++) {
            int j = std::lower_bound(nums.begin(), nums.end(), queries[i])-nums.begin();
            res[i] = (1LL*queries[i]*(2*j-n)+prefix[n]-2*prefix[j]);
        }
        return res;
    }
};