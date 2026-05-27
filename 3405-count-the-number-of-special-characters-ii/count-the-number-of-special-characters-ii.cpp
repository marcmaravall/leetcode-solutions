class Solution {
public:
    int numberOfSpecialChars(string word) {
        std::vector<int16_t> freq(127, 0);

        for (char c : word) {
            if (c > 'Z' && freq[c-32])
                freq[c] = INT16_MIN;
            else    
                freq[c]++;
        }

        int res = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] > 0 && freq[c-32] > 0)
                res++;
        }

        return res;
    }
};