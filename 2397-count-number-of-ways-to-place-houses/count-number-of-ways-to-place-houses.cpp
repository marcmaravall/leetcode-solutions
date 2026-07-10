class Solution {
public:
    int countHousePlacements(int n) {
        constexpr long long mod = 1e9+7;
        long long house = 1, space = 1;
        long long total = 2;
        for (int i = 2; i <= n; i++) {
            house = space;
            space = total;
            total = (space + house) % mod;
        }
        return (total*total) % mod;
    }
};