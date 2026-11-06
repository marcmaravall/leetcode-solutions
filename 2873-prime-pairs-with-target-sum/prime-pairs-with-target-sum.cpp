class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        std::vector<bool> sieve(n+1, false);
        std::vector<int> primes;
        for (int i = 2; i <= n/2; i++) {
            if (sieve[i]) {
                continue;
            }
            primes.push_back(i);
            for (int j = 2*i; j <= n; j += i) {
                sieve[j] = true;
            }
        }
        std::vector<std::vector<int>> res;
        for (int p : primes) {
            if (p > n/2) {
                break;
            }
            if (!sieve[p] && !sieve[n-p]) {
                res.push_back({p, n-p});
            }
        }
        return res;
    }
};