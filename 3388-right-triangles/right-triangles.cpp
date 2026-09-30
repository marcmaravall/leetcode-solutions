class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        std::vector<int> onesRow(n), onesCol(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    onesRow[i]++;
                    onesCol[j]++;
                }
            }
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res += (onesRow[i]-1)*(onesCol[j]-1);
                }
            }
        }
        return res;
    }
};