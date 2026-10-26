class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int n = grid.size(), m = grid[0].size();
        std::function<void(int, int, long long&)> count = [&](int y, int x, long long& c) {
            if (y < 0 || x < 0 || y >= n || x >= m || grid[y][x] == 0) {
                return;
            }
            c += grid[y][x];
            grid[y][x] = 0;
            count(y+1, x, c);
            count(y-1, x, c);
            count(y, x+1, c);
            count(y, x-1, c);
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    continue;
                }
                long long value = 0;
                count(i, j, value);
                if (value % k == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};