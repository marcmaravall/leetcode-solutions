class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        for (int i = 0; i < m; i++) {
            std::vector<int> diagonal;
            for (int j = 0; j < n && i+j < m; j++) {
                diagonal.push_back(mat[j][i+j]);
            }

            std::sort(diagonal.begin(), diagonal.end());
            for (int j = 0; j < n && i+j < m; j++) {
                mat[j][i+j] = diagonal[j];
            }
        }

        for (int i = 1; i < n; i++) {
            std::vector<int> diagonal;
            for (int j = 0; j < m && i+j < n; j++) {
                diagonal.push_back(mat[i+j][j]);
            }

            std::sort(diagonal.begin(), diagonal.end());
            for (int j = 0; j < m && i+j < n; j++) {
                mat[i+j][j] = diagonal[j];
            }
        }
    
        return mat;
    }
};