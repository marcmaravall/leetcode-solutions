class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res(n, std::vector<int>(n, 0));
        int i = 0, j = 0;
        int iInc = 0, jInc = 1;
        for (int val = 1; val <= n*n; val++) {
            if (jInc == 1 && (j == n-1 || res[i][j+1] != 0)) {
                iInc = 1, jInc = 0;
            } else if (iInc == 1 && (i == n-1 || res[i+1][j] != 0)) {
                iInc = 0, jInc = -1;
            } else if (jInc == -1 && (j == 0 || res[i][j-1] != 0)) {
                iInc = -1, jInc = 0;
            } else if (iInc == -1 && (i == 0 || res[i-1][j] != 0)) {
                iInc = 0, jInc = 1;
            }
            res[i][j] = val;
            i += iInc, j += jInc;
        }      
        return res;
    }
};