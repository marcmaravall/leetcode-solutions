class Solution {
public:
    bool dfs(std::vector<std::vector<int>>& grid, int i, int j) {
        if (i == grid.size()-1 && j == grid[0].size()-1)
            return true;
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return false;
        grid[i][j] = 0;
        return dfs(grid, i+1, j) || dfs(grid, i, j+1);
    }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if (!dfs(grid, 0, 0))
            return true;
        grid[0][0] = 1;
        return !dfs(grid, 0, 0);
    }
};