class Solution {
public:
    int digitRange(int n) {
        std::string str = std::to_string(n);
        char M = 0, m = 100;
        for (char c : str) {
            M = std::max(M, c);
            m = std::min(m, c);
        }

        return M-m;
    }

    int maxDigitRange(vector<int>& nums) {
        int m = 0;
        for (int n : nums) {
            m = std::max(digitRange(n), m);
        }

        int res = 0;
        for (int n : nums) {
            if (digitRange(n) == m)
                res += n;
        }
        return res;
    }
};