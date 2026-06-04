class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for (int i = num1; i <= num2; i++) {
            std::string digits = std::to_string(i);
            
            for (int j = 1; j < digits.size()-1; j++) {
                if (digits[j] < digits[j+1] && digits[j] < digits[j-1] || 
                    digits[j] > digits[j+1] && digits[j] > digits[j-1])
                    res++;
            }
        }

        return res;
    }
};