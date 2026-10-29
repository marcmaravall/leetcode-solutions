class Solution {
public:
    int countValidPrefixes(string s) {
        int res = 0, ones = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            ones += s[i] == '1';
            int zeros = i-ones+1;
            const int d = ones-zeros;
            if (d > -2 && d < 2) {
                res++;
            }
        }
        return res;
    }
};