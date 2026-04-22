class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        std::queue<std::pair<int,int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2)
                    q.push({i, j});

        int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        int res = 0;

        while (!q.empty()) {
            int sz = q.size();
            bool rotted = false;
            while (sz--) {
                auto [x, y] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nx = x + d[0], ny = y + d[1];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        rotted = true;
                    }
                }
            }
            
            if (rotted) 
                res++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) 
                    return -1;
            }
        }

        return res;
    }
};