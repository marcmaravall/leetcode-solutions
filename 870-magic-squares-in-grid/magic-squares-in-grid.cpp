class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            for (int j = 0; j < m-2; j++) {
                int a = grid[i][j], b = grid[i][j+1], c = grid[i][j+2];
                int d = grid[i+1][j], e = grid[i+1][j+1], f = grid[i+1][j+2];
                int g = grid[i+2][j], h = grid[i+2][j+1], _i = grid[i+2][j+2];
                std::array<int, 16> arr{};
                arr[a]++, arr[b]++, arr[c]++,
                arr[d]++, arr[e]++, arr[f]++,
                arr[g]++, arr[h]++, arr[_i]++;
                bool unique = true;
                for (int k = 0; k < 16; k++) {
                    if (arr[k] > 1 || ((k >= 10 || k == 0) && arr[k] != 0)) {
                        unique = false;
                        break;
                    }
                }
                if (!unique)
                    continue;
                int expected = a+b+c;
                if (d+e+f == expected && g+h+_i == expected && 
                    a+d+g == expected && b+e+h == expected && c+f+_i == expected &&
                    a+e+_i == expected && g+e+c == expected)
                    res++;
            }
        }
        return res;
    }
};