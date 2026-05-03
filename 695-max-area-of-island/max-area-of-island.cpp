class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        std::function<void(int, int)> propagate = [&](int y, int x) {
            if (y < 0 || x < 0 || x >= m || y >= n || grid[y][x] != 1) {
                return;
            }

            area++;
            grid[y][x] = 2;
            propagate(y+1, x);
            propagate(y-1, x);
            propagate(y, x+1);
            propagate(y, x-1);
        };
        
        int res = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (grid[y][x] != 1)
                    continue;
                area = 0;
                propagate(y, x);
                res = max(area, res);
            }
        }
        return res;
    }
};