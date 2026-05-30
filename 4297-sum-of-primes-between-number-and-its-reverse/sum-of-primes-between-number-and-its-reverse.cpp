class Solution {
public:
    int rev(int n) {
        std::string str = std::to_string(n);
        std::reverse(str.begin(), str.end());
        n = std::stoi(str);

        return n;
    }

    int sumOfPrimesInRange(int n) {
        std::vector<bool> prime(1001, true);
        for (int i = 2; i < prime.size(); i++) {
            int n = i;
            bool p = prime[i];
            while (n < prime.size()) {
                prime[n] = false;
                n += i;
            }
            if (p) prime[i] = true;
        }
        prime[1] = false;
        
        int res = 0;
        for (int i = min(rev(n), n); i <= max(n, rev(n)); i++) {
            if (prime[i]) {
                res+=i;
            }
        }
        return res;
    }
};