class Solution {
public:
    int minChanges(int n, int k) {
        int res = 0;
        for (int i = 31; i >= 0; i--) {
            int mask = 1 << i;
            bool a = n & mask, b = k & mask;
            if (b && !a) {
                return -1;
            }
            if (!a == b) {
                res++;
            }
        }
        return res;
    }
};