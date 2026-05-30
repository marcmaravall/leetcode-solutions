class Solution {
public:
    bool prime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    int sumOfPrimesInRange(int n) {
        int num = n;
        int rev = 0;

        while (num != 0) {
            int digit = num % 10;
            rev = rev * 10 + digit;
            num /= 10;
        }

        int l = min(n, rev);
        int r = max(n, rev);

        int res = 0;

        for (int i = l; i <= r; i++) {
            if (prime(i))
                res += i;
        }

        return res;
    }
};