class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *std::max_element(nums.begin(), nums.end());
        std::vector<int> freq(mx+1, 0);
        std::vector<long long> gcd(mx+1, 0);
        for (int n : nums)
            freq[n]++;
        for (int i = mx; i > 0; i--) {
            long long sm = 0, extra = 0;
            for (int j = i; j <= mx; j+=i)
                sm += freq[j], extra += gcd[j];
            gcd[i] = (sm * (sm-1)/2)-extra;
        }
        std::partial_sum(gcd.begin(), gcd.end(), gcd.begin());
        const int n = queries.size();
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) 
            res[i] = std::ranges::upper_bound(gcd, queries[i]) - gcd.begin();
        return res;
    }
};