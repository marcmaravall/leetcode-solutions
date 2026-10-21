class Solution {
public:
    bool vowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    bool halvesAreAlike(string s) {
        int v = 0;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            if (vowel(s[i])) {
                if (i < n/2) v++;
                else v--;
            }
        }
        return v == 0;
    }
};