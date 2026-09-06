class Solution {
public:
    int numDistinct(string s, string t) {
        const int ss = s.size(), ts = t.size();
        std::vector<uint64_t> dp(ts+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= ss; i++) {
            for (int j = std::min(i, ts); j >= 1; j--) {
                if (s[i-1] == t[j-1]) {
                    dp[j] += dp[j-1];
                }
            }
        }
        return dp[ts];
    }
};
