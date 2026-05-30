class Solution {
public:
    int rev(int n) {
        std::string str = std::to_string(n);
        std::reverse(str.begin(), str.end());
        n = std::stoi(str);

        return n;
    }

    bool prime(int n) {
        if (n == 1)
            return false;
        else if (n <= 3)
            return true;
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int res = 0;
        for (int i = min(rev(n), n); i <= max(n, rev(n)); i++) {
            if (prime(i)) {
                std::cout << i << "\n";
                res+=i;
            }
        }
        return res;
    }
};