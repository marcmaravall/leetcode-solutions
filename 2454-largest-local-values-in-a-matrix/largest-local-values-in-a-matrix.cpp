class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        std::vector<std::vector<int>> res(n-2, std::vector<int>(n-2));
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < n-2; j++) {
                res[i][j] = std::max({
                    grid[i][j], grid[i][j+1], grid[i][j+2],
                    grid[i+1][j], grid[i+1][j+1], grid[i+1][j+2],
                    grid[i+2][j], grid[i+2][j+1], grid[i+2][j+2]});
            }
        }
        return res;
    }
};