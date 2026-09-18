class Solution {
public:
    int longestBalanced(string s) {
        auto valid = [](const std::array<int, 26>& freq) -> bool {
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
            std::array<int, 26> freq = {};
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                if (valid(freq))
                    res = std::max(res, j-i+1);
            }
        }
        return res;
    }
};