class Solution {
public:
    int calculateScore(int a, int b) {
        int s1 = 0, s2 = 0;
        for (int i = 6; i >= 0; i--) {
            int mask = 1 << i;
            s1 += a & mask ? 1 : 0;
            s2 += b & mask ? 1 : 0;
        }
        return s1 >= s2 ? s1*s2 : s2/s1;
    }
};