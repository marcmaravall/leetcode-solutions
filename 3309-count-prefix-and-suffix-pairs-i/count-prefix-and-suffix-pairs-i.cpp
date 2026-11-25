class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        auto is = [](const auto& str1, const auto& str2) -> bool {
            const int n = str1.size(), m = str2.size();
            if (n > m) {
                return false;
            }
            for (int i = 0; i < n; i++) {
                if (str1[i] != str2[i] || str1[n-i-1] != str2[m-i-1]) {
                    return false;
                }
            }
            return true;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (is(words[i], words[j])) {
                    res++;
                }
            }
        }
        return res;
    }
};