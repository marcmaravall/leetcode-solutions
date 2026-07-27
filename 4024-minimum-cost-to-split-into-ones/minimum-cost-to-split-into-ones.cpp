class Solution {
public:
    int minCost(int n) {
        int res = 0;
        for (int i = n-1; i >= 1; i--) {
            res+=i;
        }
        return res;
    }
};