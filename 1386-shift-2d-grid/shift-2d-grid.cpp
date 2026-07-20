class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        std::vector<int> arr;
        for (auto& vec : grid)
            arr.insert(arr.end(), vec.begin(), vec.end());

        const int s = arr.size();
        for (int i = 0; i < k; i++) {
            int last = arr[s-1];
            for (int j = s-2; j >= 0; j--) {
                arr[j+1] = arr[j];
            }
            arr[0] = last;
        }
        
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