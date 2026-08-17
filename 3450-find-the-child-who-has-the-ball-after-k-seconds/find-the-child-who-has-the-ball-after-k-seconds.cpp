class Solution {
public:
    int numberOfChild(int n, int k) {
        n--;
        int mod = k % n;
        int div = k / n;
        if (div % 2 == 0)
            return mod;
        else return n-mod;
    }
};