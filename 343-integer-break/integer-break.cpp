class Solution {
public:
    int integerBreak(int n) {
        if (n == 2)
            return 1;
        else if (n == 3)
            return 2;

        int threes = n / 3;
        int mod = n % 3;
        if (mod == 1) {
            threes -= 1;
            mod = 4;
        } else if (mod == 0) {
            mod = 1;
        }

        return pow(3, threes) * mod;
    }
};