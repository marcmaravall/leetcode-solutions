class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        std::vector<int> cols(m), rows(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                const int val = grid[i][j] ? 1 : -1;
                rows[i] += val, cols[j] += val;
            }
        }
        std::vector<std::vector<int>> diff(n, std::vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                diff[i][j] = rows[i] + cols[j];
        }
        return diff;
    }
};