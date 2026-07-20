class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        std::vector<int> arr;
        for (auto& vec : grid)
            arr.insert(arr.end(), vec.begin(), vec.end());

        k %= arr.size();
        std::reverse(arr.begin(), arr.end());
        std::reverse(arr.begin(), arr.begin()+k);
        std::reverse(arr.begin()+k, arr.end());
        
        const int n = grid.size();
        const int m = grid[0].size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                grid[y][x] = arr[y*m+x];
            }
        }

        return grid;
    }
};