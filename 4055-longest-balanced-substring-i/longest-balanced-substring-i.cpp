class Solution {
public:
    int longestBalanced(string s) {
        auto valid = [](int freq[26]) -> bool {
            int expected = -1;
            for (int i = 0; i < 26; i++) {
                if (freq[i] != 0) {
                    if (expected == -1)
                        expected = freq[i];
                    if (expected != freq[i])
                        return false;
                }
            }
            return true;
        };
        int res = 1;
        const int n = s.size();
        for (int i = 0; i < n; i++) {
            std::string str = "";
            int freq[26] = {};
            for (int j = i; j < n; j++) {
                str += s[j];
                freq[s[j]-'a']++;
                if (valid(freq))
                    res = std::max(res, (int)str.size());
            }
        }
        return res;
    }
};