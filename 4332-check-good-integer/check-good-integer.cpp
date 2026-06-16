class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitSum = 0, squareSum = 0;
        for (; n != 0; n /= 10) {
            int d = n%10;
            digitSum += d;
            squareSum += d*d;
        }

        return squareSum-digitSum >= 50;
    }
};