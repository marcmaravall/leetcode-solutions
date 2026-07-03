class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        std::vector<int> freq(60, 0);
        for (auto& t : time) {
            freq[t % 60]++;
        }

        int res = 0;
        res += (long long)freq[0] * (long long)(freq[0] - 1) / 2;
        res += (long long)freq[30] * (long long)(freq[30] - 1) / 2;

        for (int i = 1; i < 30; i++) {
            res += freq[i] * freq[60-i];
        }

        return res;
    }
};