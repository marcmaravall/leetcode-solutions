class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        std::vector<int> freq(24);
        for (int h : hours)
            freq[h%24]++;

        long long res = 0;
        res += (long long)freq[0] * (long long)(freq[0]-1) / 2;
        res += (long long)freq[12] * (long long)(freq[12]-1) / 2;

        for (int i = 1; i < 12; i++) {
            res += freq[i]*freq[24-i];
        }

        return res;
    }
};