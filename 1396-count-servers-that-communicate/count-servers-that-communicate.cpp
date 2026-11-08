class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        const int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!grid[i][j])
                    continue;
                int servers = 0;
                for (int _i = 0; _i < n; _i++) {
                    servers += grid[_i][j];
                }
                for (int _j = 0; _j < m; _j++) {
                    servers += grid[i][_j];
                }
                if (servers > 2)
                    res++;
            }
        }
        return res;
    }
};