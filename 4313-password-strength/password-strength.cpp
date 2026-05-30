class Solution {
public:
    int passwordStrength(string password) {
        std::vector<int> freq(127, 0);
        int res = 0;
        for (char c : password) {
            freq[c]++;
        }

        for (char c = 'a'; c <= 'z'; c++) {
            if (freq[c] > 0) 
                res++;
        }
        for (char c = 'A'; c <= 'Z'; c++) {
            if (freq[c] > 0) 
                res+=2;
        }
        for (char c = '0'; c <= '9'; c++) {
            if (freq[c] > 0) 
                res+=3;
        }
        
        if (freq['!'] > 0) res += 5;
        if (freq['@'] > 0) res += 5;
        if (freq['#'] > 0) res += 5;
        if (freq['$'] > 0) res += 5;

        return res;
    }
};