class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        std::sort(beans.begin(), beans.end());
        const int n = beans.size();
        long long total = std::accumulate(beans.begin(), beans.end(), 0LL);
        long long res = INT64_MAX;
        for (int i = 0; i < n; i++) {
            long long curr = total - (long long)beans[i] * (n-i);
            res = std::min(res, curr);
        }
        return res;
    }
};