class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        std::sort(s.begin(), s.end(), std::greater<int>());
        if (s[s.size()-1] == '1')
            return s;

        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '1') {
                std::swap(s[i], s[s.size()-1]);
                break;
            }
        }
        return s;
    }
};