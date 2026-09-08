class Solution {
public:
    int myAtoi(string s) {
        const int n = s.size();
        if (n == 0)
            return 0;
        int index = 0;
        while (index < n && s[index] == ' ')
            index++;
        if (index >= n)
            return 0;
        int sign = 1;
        if (s[index] == '+')
            index++;
        else if (s[index] == '-') {
            sign = -1;
            index++;
        }
        long long num = 0;
        for (index; index < n && s[index] >= '0' && s[index] <= '9'; index++) {
            int digit = s[index]-'0';
            num *= 10;
            num += digit;
            if (num*sign <= INT_MIN)
                return INT_MIN;
            if (num*sign >= INT_MAX)
                return INT_MAX;
        }
        return static_cast<int>(num*sign);
    }
};