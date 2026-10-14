class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        std::string res(num, '0');
        for (int i = 0; i < num && sum > 0; i++) {
            int curr = std::min(9, sum);
            sum -= curr;
            res[i] = curr+'0';
        }
        if (sum != 0) {
            return "";
        }
        return res;
    }
};