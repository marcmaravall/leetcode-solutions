class Solution {
public:
    int uniquePaths(int m, int n) {
        int moves = m + n-2;
        int k = min(m-1, n-1);
        long long res = 1;

        for (int i = 0; i < k; i++) {
            res *= (moves-i);
            res /= i+1;
        }
        return res;
    }
};