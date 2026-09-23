class Solution {
public:
    int brokenCalc(int x, int y) {
        int res = 0;
        while (x < y) {
            res += y%2+1;
            y = (y+1)/2;
        }
        return res+x-y;
    }
};