class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int f1[26] = {}, f2[26] = {};
        for (char c : word1) {
            f1[c-'a']++;
        }
        for (char c : word2) {
            f2[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (!f1[i]) {
                continue;
            }
            for (int j = 0; j < 26; j++) {
                if (!f2[j]) {
                    continue;
                }
                int d1 = 0, d2 = 0;
                for (int k = 0; k < 26; k++) {
                    int a = f1[k];
                    int b = f2[k];
                    if (k == i) a--;
                    if (k == j) b--;
                    if (k == j) a++;
                    if (k == i) b++;
                    d1 += (a > 0);
                    d2 += (b > 0);
                }

                if (d1 == d2) {
                    return true;
                }
            }
        }

        return false;
    }
};