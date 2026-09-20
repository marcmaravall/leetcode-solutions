class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        const int s = std::min(n, limit);
        for (int i = 0; i <= s; i++) {
            if (n-i > 2*limit)
                continue;
            res += std::min(n-i, limit)-std::max(0, n-i-limit)+1;
        }
        return res;
    }
};