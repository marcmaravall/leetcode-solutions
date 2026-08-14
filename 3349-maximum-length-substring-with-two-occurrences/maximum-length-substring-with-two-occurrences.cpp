class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left = 0;
        int right = 0;
        int res = 0;
        const int n = s.size();
        std::vector<int> freq(127, 0);
        while (left < n && right < n) {
            if (freq[s[right]] >= 2) {
                freq[s[left++]]--;
            } else {
                freq[s[right++]]++;
                res = std::max(right-left, res);
            }
        }
        return res;
    }
};