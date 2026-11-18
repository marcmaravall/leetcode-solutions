class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        auto count = [&](int r, int c) {
            int size = 0;
            while (r+size < n && c+size < m) {
                bool valid = true;
                for (int j = c; j <= c + size; j++) {
                    if (matrix[r+size][j] == 0) {
                        valid = false;
                        break;
                    }
                }
                for (int i = r; valid && i < r + size; i++) {
                    if (matrix[i][c+size] == 0) {
                        valid = false;
                    }
                }
                if (!valid) {
                    break;
                }
                res++;
                size++;
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    count(i, j);
                }
            }
        }
        return res;
    }
};