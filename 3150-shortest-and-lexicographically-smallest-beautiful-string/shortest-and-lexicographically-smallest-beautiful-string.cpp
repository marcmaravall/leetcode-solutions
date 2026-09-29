class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        const int n = s.size();
        int left = 0, ones = 0;
        std::string res = "";
        for (int right = 0; right < n; right++) {
            ones += s[right] == '1';
            while (left <= right && (ones > k || s[left] == '0')) {
                ones -= s[left] == '1';
                left++;
            }
            if (ones == k) {
                int size = right - left + 1;
                if (res.empty() || size < res.size() || (size == res.size() && s.compare(left, size, res) < 0)) {
                    res = s.substr(left, size);
                }
            }
        }
        return res;
    }
};