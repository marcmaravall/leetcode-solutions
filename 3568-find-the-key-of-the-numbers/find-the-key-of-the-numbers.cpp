class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int a = std::min(num1 % 10, std::min(num2 % 10, num3 % 10));
        int b = std::min((num1/10) % 10, std::min((num2/10) % 10, (num3/10) % 10));
        int c = std::min((num1/100) % 10, std::min((num2/100) % 10, (num3/100) % 10));
        int d = std::min((num1/1000) % 10, std::min((num2/1000) % 10, (num3/1000) % 10));
        return a + b*10 + c*100 + d*1000;
    }
};