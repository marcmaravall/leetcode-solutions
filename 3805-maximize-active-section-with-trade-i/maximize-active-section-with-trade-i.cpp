class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = std::count(s.begin(), s.end(), '1');
        int best = 0;
        int last = INT_MIN;
        const int n = s.size();
        int i = 0;
        while (i < n) {
            int start = i;
            while (i < n && s[i] == s[start]) 
                i++;
            if (s[start] == '0') {
                int current = i-start;
                best = std::max(best, current+last);
                last = current;
            }
        }
        return ones+best;
    }
};