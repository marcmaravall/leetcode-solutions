class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        const int n = grid.size();
        for (int i = 0; i < n; i++) {
            int maxC = 0;
            for (int j = 0; j < n; j++) {
                maxC = std::max(maxC, grid[i][j]);
            }
            for (int j = 0; j < n; j++) {
                int maxR = 0;
                for (int y = 0; y < n; y++) {
                    maxR = std::max(maxR, grid[y][j]);
                }
                res += std::max(std::min(maxR, maxC)-grid[i][j], 0);
            }
        }
        return res;
    }
};