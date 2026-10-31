class Solution {
public:
    int countGoodSubstrings(string s) {
        const int n = s.size();
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            res += (s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]);
        }
        return res;
    }
};