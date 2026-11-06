class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        std::vector<bool> sieve(n+1, false);
        for (int i = 2; i <= n/2; i++) {
            if (sieve[i]) {
                continue;
            }
            for (int j = 2*i; j <= n; j += i) {
                sieve[j] = true;
            }
        }
        std::vector<std::vector<int>> res;
        for (int i = 2; i <= n/2; i++) {
            if (!sieve[i] && !sieve[n-i]) {
                res.push_back({i, n-i});
            }
        }
        return res;
    }
};