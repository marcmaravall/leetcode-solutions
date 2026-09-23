class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int res = 0;
        while (startValue < target) {
            res += target%2+1;
            target = (target+1)/2;
        }
        return res+startValue-target;
    }
};