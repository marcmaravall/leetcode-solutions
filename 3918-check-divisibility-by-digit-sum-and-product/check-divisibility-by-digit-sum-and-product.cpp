class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int mult = 1;
        int cpy = n;
        while (cpy > 9) {
            int digit = cpy%10;
            sum += digit;
            mult *= digit;
            cpy /= 10;
        }

        sum += cpy;
        mult *= cpy;
        
        return (n % (sum+mult)) == 0;
    }
};