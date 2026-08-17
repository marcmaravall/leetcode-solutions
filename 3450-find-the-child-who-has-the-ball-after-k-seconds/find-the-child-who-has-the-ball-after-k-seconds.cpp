class Solution {
public:
    int numberOfChild(int n, int k) {
        int res = 0;
        int dir = 1;
        for (k; k > 0; k--) {
            if (res == 0)
                dir = 1;
            else if (res == n-1)
                dir = -1;
            res += dir;
        }
        return res;
    }
};