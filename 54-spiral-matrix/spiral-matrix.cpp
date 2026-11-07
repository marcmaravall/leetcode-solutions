class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();
        std::vector<int> res(n*m);
        int index = 0;
        const int min = std::min(n, m);
        for (int depth = 0; depth < min/2; depth++) {
            for (int i = depth; i < m-depth; i++) {
                res[index++] = matrix[depth][i];
            }
            for (int i = depth+1; i < n-depth; i++) {
                res[index++] = matrix[i][m-depth-1];
            }
            for (int i = m-depth-2; i >= depth; i--) {
                res[index++] = matrix[n-depth-1][i];
            }
            for (int i = n-depth-2; i >= depth+1; i--) {
                res[index++] = matrix[i][depth];
            }
        }
        if (n == m && n % 2 == 0)
            return res;
        if (n > m && m%2 == 1) {
            for (int i = 0; i <= n-m; i++) {
                res[index++] = matrix[m/2+i][m/2];
            }
        } else if (n%2 == 1) {
            for (int i = 0; i <= m-n; i++) {
                res[index++] = matrix[n/2][n/2+i];
            }
        }
        return res;
    }
};