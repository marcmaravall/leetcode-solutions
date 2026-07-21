class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res = 0;
        int ones = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
            else 
                res++;
            res = std::min(res, ones);
        }
        return res;
    }
};