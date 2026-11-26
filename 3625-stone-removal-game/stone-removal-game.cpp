class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool res = false;
        while (n >= stones) {
            n -= stones--;
            res = !res;
        }
        return res;
    }
};