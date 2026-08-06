class Solution {
public:
    int pdigits(int n) {
        int res = 1;
        while (n > 0) {
            int digit = n%10;
            res *= digit;
            n /= 10;
        }
        return res;
    }

    int smallestNumber(int n, int t) {
        while (pdigits(n) % t != 0)
            n++;
        return n;
    }
};