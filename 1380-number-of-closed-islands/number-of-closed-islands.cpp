class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        std::function<bool(int, int)> dfs = [&](int y, int x) -> bool {
            if (y < 0 || x < 0 || y >= n || x >= m) {
                return false;
            }
            if (grid[y][x] == 1) {
                return true;
            }
            grid[y][x] = 1;
            bool up = dfs(y-1, x);
            bool down = dfs(y+1, x);
            bool left = dfs(y, x-1);
            bool right = dfs(y, x+1);
            return up && down && left && right;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    res++;
                }
            }
        }
        return res;
    }
};