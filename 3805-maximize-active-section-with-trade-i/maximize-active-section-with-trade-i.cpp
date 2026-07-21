class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            ones += c == '1';
        const int n = s.size();
        int i = 0;
        int best = 0;
        int prev = INT_MIN;
        int current = 0;
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start])
                i++;
            if (s[start] == '0') {
                current = i-start;
                best = std::max(best, prev+current);
                prev = current;
            }
        }
        return ones + best;
    }
};