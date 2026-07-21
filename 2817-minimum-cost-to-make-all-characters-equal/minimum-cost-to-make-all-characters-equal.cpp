class Solution {
public:
    long long minimumCost(string s) {
        long long res = 0;
        const int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1])
                res += std::min(i, n-i);
        }
        return res;
    }
};