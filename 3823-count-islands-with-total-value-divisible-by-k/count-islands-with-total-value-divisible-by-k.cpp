class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        const int n = grid.size(), m = grid[0].size();
        auto count = [&](auto&& self, int y, int x) -> long long {
            if (y < 0 || x < 0 || y >= n || x >= m || grid[y][x] == 0) {
                return 0;
            }
            long long sum = grid[y][x];
            grid[y][x] = 0;
            sum += self(self, y+1, x);
            sum += self(self, y-1, x);
            sum += self(self, y, x+1);
            sum += self(self, y, x-1);
            return sum;
        };
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long value = count(count, i, j);
                    if (value % k == 0) {
                        res++;
                    }
                }
            }
        }
        return res;
    }
};