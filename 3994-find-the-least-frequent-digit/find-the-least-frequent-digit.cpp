class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int f[10] = {};
        while (n) {
            f[n%10]++;
            n /= 10;
        }
        int res = 0;
        int freq = INT_MAX;
        for (int i = 0; i < 10; i++) {
            if (f[i] != 0 && f[i] < freq) {
                res = i;
                freq = f[i];
            }
        }
        return res;
    }
};