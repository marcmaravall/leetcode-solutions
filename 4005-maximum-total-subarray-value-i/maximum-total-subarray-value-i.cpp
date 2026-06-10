class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int m = INT_MAX, M = 0;
        for (int n : nums) {
            m = min(n, m);
            M = max(n, M);
        }
        return (long long)(M-m) * (long long)k;
    }
};