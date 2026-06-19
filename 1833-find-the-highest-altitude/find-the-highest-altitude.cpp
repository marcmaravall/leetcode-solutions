class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0;
        int current = 0;
        for (int n : gain) {
            current += n;
            res = max(res, current);
        }
        return res;
    }
};