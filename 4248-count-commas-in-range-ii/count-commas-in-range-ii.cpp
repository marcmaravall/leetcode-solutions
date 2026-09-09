class Solution {
public:
// xd
    long long countCommas(long long n) {
        if (n < 1e3)
            return 0;
        if (n < 1e6)
            return n-999;
        else if (n < 1e9)
            return n-999999 + n-999;
        else if (n < 1e12)
            return n-999999999 + n-999999 + n-999;
        else if (n < 1e15)
            return n-999999999999 + n-999999999 + n-999999 + n-999;
        return n-999999999999999 + n-999999999999 + n-999999999 + n-999999 + n-999;
    }
};