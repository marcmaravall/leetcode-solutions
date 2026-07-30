class Solution {
public:
    int minimumPushes(string word) {
        std::vector<int> freq(27, 0);
        for (char c : word) {
            freq[c-'a']++;
        }
        std::sort(freq.begin(), freq.end());
        int res = 0;
        int current = 0;
        for (int i = 0; i < 27; i++) {
            if (freq[i] == 0)
                continue;
            current++;
            if (current > 24)
                res += freq[i]*4;
            else if (current > 16)
                res += freq[i]*3;
            else if (current > 8)
                res += freq[i]*2;
            else res += freq[i];
        }
        return res;
    }
};