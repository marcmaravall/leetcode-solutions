class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            ones += c == '1';
        const int n = s.size();
        std::vector<int> zeros;
        int i = 0;
        while (i < n) {
            int st = i;
            while (i < n && s[st] == s[i])
                i++;
            if (s[st] == '0') {
                zeros.push_back(i-st);
            }
        }

        const int m = zeros.size();
        if (m <= 1)
            return ones;
        int best = 0;
        for (int i = 0; i < m-1; i++)
            best = std::max(best, zeros[i] + zeros[i+1]);
        return ones + best;
    }
};