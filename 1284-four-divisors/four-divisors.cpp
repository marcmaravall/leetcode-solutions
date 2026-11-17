class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        for (int x : nums) {
            int divisors = 0;
            int sum = 0;
            for (int i = 1; i*i <= x; i++) {
                if (x % i == 0) {
                    if (i*i != x) {
                        divisors++;
                        sum += x/i;
                    }
                    sum += i;
                    divisors++;
                }
            }
            if (divisors == 4) {
                res += sum;
            }
        }
        return res;
    }
};