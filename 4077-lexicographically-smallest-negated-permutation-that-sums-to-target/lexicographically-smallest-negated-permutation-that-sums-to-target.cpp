class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        int64_t total = ((int64_t)n*((int64_t)n+1LL)) / 2LL;
        int64_t diff = (int64_t)total - (int64_t)target;

        if (diff < 0 || diff % 2 != 0)
            return {};

        int64_t sum = diff / 2;
        std::vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = i+1;
        }

        for (int i = n; i > 0; i--) {
            if (i <= sum) {
                res[i-1] *= -1;
                sum -= i;
            }

            if (sum == 0)
                break;
        }

        if (sum != 0)
            return {};

        std::sort(res.begin(), res.end());
        return res;
    }
};