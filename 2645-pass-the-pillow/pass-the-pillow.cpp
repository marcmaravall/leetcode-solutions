class Solution {
public:
    int passThePillow(int n, int k) {
        int res = 1;
        int dir = 1;
        for (k; k > 0; k--) {
            if (res == 1)
                dir = 1;
            else if (res == n)
                dir = -1;
            res += dir;
        }
        return res;
    }
};