class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int m = 1 << i;
            if ((start & m) ^ (goal & m)) {
                res++;
            }
        }
        return res;
    }
};