class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        const int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int consonants = 0, vowels = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    vowels++;
                else consonants++;
                if (vowels == consonants && vowels*consonants % k == 0)
                    res++;
            }
        }
        return res;
    }
};