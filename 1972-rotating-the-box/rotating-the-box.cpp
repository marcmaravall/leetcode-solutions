class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = m-1; j > 0; j--) {
                j = min(j, m-1);
                char current = boxGrid[i][j];
                if (current == '.' && boxGrid[i][j-1] == '#') {
                    std::swap(boxGrid[i][j], boxGrid[i][j-1]);
                    if (j < m)
                        j+=2;
                }
            }
        }
        
        std::vector<std::vector<char>> res(m, std::vector<char>(n, '.'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[j][i] = boxGrid[n-i-1][j];
            }
        }
        return res;
    }
};