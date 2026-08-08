class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::vector<std::array<int, 10>> freq(30);
        int pow = 1;
        for (int i = 0; pow < (1 << 30); i++) {
            int cpy = pow;
            while (cpy > 0) {
                int digit = cpy%10;
                freq[i][digit]++;
                cpy /= 10;
            }
            pow <<= 1;
        }

        std::array<int, 10> nfreq {};
        while (n > 0) {
            int digit = n % 10;
            nfreq[digit]++;
            n /= 10;
        }

        for (auto& f : freq) {
            bool res = true;
            for (int i = 0; i <= 9; i++) {
                if (f[i] != nfreq[i]) {
                    res = false;
                    break;
                }
            }
            if (res)
                return true;
        }

        return false;
    }
};