class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    int top = (i > 0) ? mat[i-1][j] : 1e9;
                    int left = (j > 0) ? mat[i][j-1] : 1e9;
                    mat[i][j] = min(top, left) + 1;
                } else {
                    mat[i][j] = 0;
                }
            }
        }

        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (mat[i][j] != 1) {
                    int bottom = (i < n-1) ? mat[i+1][j] : 1e9;
                    int right = (j < m-1) ? mat[i][j+1] : 1e9;
                    mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
                }
            }
        }

        return mat;
    }
};