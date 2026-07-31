class Solution {
public:
    int minimumChairs(string s) {
        int res = 0;
        int chairs = 0;
        for (char c : s) {
            if (c == 'E')
                res = std::max(res, ++chairs);
            else chairs--;
        }
        return res;
    }
};