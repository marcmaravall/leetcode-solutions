class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = std::count(s.begin(), s.end(), '1');
        int prev = INT_MIN;
        int best = 0;
        int i = 0;
        const int n = s.size();
        while (i < n) {
            int st = i;
            while (i < n && s[i] == s[st])
                i++;
            if (s[st] == '0') {
                int curr = i-st;
                best = std::max(best, curr+prev);
                prev = curr;
            }
        }
        return ones+best;
    }
};