class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res = static_cast<long long>(n)*static_cast<long long>(m);
        res -= n % 2 == 1 && m % 2 == 1;
        res /= 2;
        return res;
    }
};