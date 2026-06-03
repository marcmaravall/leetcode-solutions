class Solution {
public:
    int maximumSum(vector<int>& nums) {
        // n % 3 results in range [0, 2]
        std::vector<int> _0;
        std::vector<int> _1;
        std::vector<int> _2;

        for (int n : nums) {
            int mod = n % 3;
            if (mod == 0) _0.push_back(n);
            if (mod == 1) _1.push_back(n);
            if (mod == 2) _2.push_back(n);
        }
        std::sort(_0.begin(), _0.end(), std::greater<int>());
        std::sort(_1.begin(), _1.end(), std::greater<int>());
        std::sort(_2.begin(), _2.end(), std::greater<int>());

        int res = 0;
        if (_0.size() >= 3)
            res = max(res, _0[0] + _0[1] + _0[2]);
        if (_1.size() >= 3)
            res = max(res, _1[0] + _1[1] + _1[2]);
        if (_2.size() >= 3)
            res = max(res, _2[0] + _2[1] + _2[2]);
        if (_0.size() >= 1 && _1.size() >= 1 && _2.size() >= 1)
            res = max(res, _0[0] + _1[0] + _2[0]);
    
        return res;
    }
};