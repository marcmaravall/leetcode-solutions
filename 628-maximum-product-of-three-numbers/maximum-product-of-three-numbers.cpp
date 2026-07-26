class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        int _b = INT_MAX, _c = INT_MAX;
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

        return std::max(a*b*c, a*_b*_c);
    }
};