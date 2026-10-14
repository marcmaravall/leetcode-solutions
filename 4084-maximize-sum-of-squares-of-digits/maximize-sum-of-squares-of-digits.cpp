class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        std::string res(num, '0');
        int index = 0;
        while (index < num && sum > 0) {
            int curr = std::min(9, sum);
            sum -= curr;
            res[index++] = curr+'0';
        }
        if (sum != 0)
            return "";
        return res;
    }
};