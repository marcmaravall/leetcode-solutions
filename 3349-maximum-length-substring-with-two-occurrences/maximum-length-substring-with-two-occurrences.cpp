class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        const int n = s.size();
        std::vector<int> freq(27, 0);
        while (left < n && right < n) {
            if (freq[s[right]-'a'] >= 2) {
                freq[s[left++]-'a']--;
            } else {
                freq[s[right++]-'a']++;
                res = std::max(right-left, res);
            }
        }
        return res;
    }
};