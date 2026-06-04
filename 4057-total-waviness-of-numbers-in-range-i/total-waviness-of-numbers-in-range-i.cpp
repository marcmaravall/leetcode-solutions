class Solution {
public:
    int waviness(int n) {
        if (n <= 100)
            return 0;

        std::vector<int> digits;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        
        int out = 0;
        for (int i = 1; i < digits.size()-1; i++) {
            if ((digits[i] > digits[i-1] && digits[i] > digits[i+1]) ||
                (digits[i] < digits[i-1] && digits[i] < digits[i+1]))
                out++;
        }

        return out;
    }

    int totalWaviness(int num1, int num2) {
        int res = 0;
        for (int i = num1; i <= num2; i++) {
            res += waviness(i);
        }

        return res;
    }
};