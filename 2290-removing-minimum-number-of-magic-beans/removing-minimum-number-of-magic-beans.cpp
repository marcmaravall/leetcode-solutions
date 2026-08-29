class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        const int n = beans.size();
        std::vector<long long> prefix(n);
        prefix[0] = beans[0];
        for (int i = 1; i < n; i++)
            prefix[i] = beans[i]+prefix[i-1];
        long long res = INT64_MAX;
        for (int i = 0; i < n; i++) {
            long long curr = 0;
            if (i != 0)
                curr += prefix[i-1];
            if (i < n-1) {
                int s = n-i-1;
                curr += (prefix[n-1]-prefix[i])-((long long)s*(long long)beans[i]);
            }
            res = std::min(res, curr);
            while (i < n-1 && beans[i] == beans[i+1])
                i++;
        }
        return res;
    }
};