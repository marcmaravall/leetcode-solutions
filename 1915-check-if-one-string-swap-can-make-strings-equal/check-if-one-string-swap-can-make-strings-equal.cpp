class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int diff = 0;
        int a = 0, b = 0;
        const int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                if (++diff > 2) {
                    return false;
                }
                if (a) {
                    b = i;
                } else {
                    a = i;
                }
            }
        }
        if (diff == 0) {
            return true;
        }
        return diff == 2 && s1[a] == s2[b] && s2[a] == s1[b];
    }
};