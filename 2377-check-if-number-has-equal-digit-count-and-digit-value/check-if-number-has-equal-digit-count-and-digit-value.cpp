class Solution {
public:
    bool digitCount(string num) {
        std::array<int, 10> freq;
        for (char c : num)
            freq[c-'0']++;
        const int n = num.size();
        for (int i = 0; i < n; i++) {
            if (freq[i] != num[i]-'0')
                return false;
        }
        return true;
    }
};