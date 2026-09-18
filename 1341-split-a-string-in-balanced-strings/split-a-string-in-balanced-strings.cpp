class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            int freq[2] = {0};
            while (i < n && (freq[0]*freq[1] == 0 || freq[0] != freq[1])) {
                bool b = s[i] == 'R' ? 0 : 1;
                freq[b]++;
                i++;
            }
            i--;
            if (freq[0] == freq[1])
                res++;
        }
        return res;
    }
};