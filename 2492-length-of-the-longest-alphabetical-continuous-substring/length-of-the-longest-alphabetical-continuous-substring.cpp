class Solution {
public:
    int longestContinuousSubstring(string s) {
        int res = 1;
        const int n = s.size();
        for (int i = 0; i < n-1; i++) {
            int length = 1;
            while (i < n-1 && s[i+1] == s[i]+1) {
                length++;
                i++;
            }
            res = max(res, length);
        }
        return res;
    }
};