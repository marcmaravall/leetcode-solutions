class Solution {
public:
    int distinctSubseqII(string s) {
        int res = 0;
        int dp[26] = {0};
        constexpr int mod = 1e9+7;
        for (char c : s) {
            c -= 'a';
            int add = (res-dp[c]+mod)%mod;
            dp[c] = res+1;
            res = (add+dp[c])%mod;
        }
        return res;
    }
};