class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        constexpr int M = 1e5;
        
        long long a = INT_MIN, b = INT_MIN, c = INT_MIN;
        long long _b = INT_MAX, _c = INT_MAX;
        for (int n : nums) {
            if (n <= _b) {
                _c = _b;
                _b = n;
            }
            else if (n < _b)
                _b = n;
            else if (n < _c)
                _c = n;

            if (n >= a) {
                c = b;
                b = a;
                a = n;
            } else if (n >= b) {
                c = b;
                b = n;
            } else if (n > c)
                c = n;
        }

        long long res = 0;
        // XD
        
        res = std::max(res, a*b*M);
        res = std::max(res, a*M*c);
        res = std::max(res, M*b*c);

        res = std::max(res, a*b*-M);
        res = std::max(res, a*-M*c);
        res = std::max(res, -M*b*c);

        res = std::max(res, a*_b*M);
        res = std::max(res, a*M*_c);
        res = std::max(res, M*_b*_c);

        res = std::max(res, a*_b*-M);
        res = std::max(res, a*-M*_c);
        res = std::max(res, -M*_b*_c);

        return res;
    }
};