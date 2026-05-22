class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 0; i < n; i++) {
            std::vector<int> map(n+1, 0);
            for (int j = 0; j < n; j++) {
                map[matrix[i][j]]++;
            }
            for (int j = 1; j <= n; j++) {
                if (map[j] == 0)
                    return false;
            }
        }
        for (int i = 0; i < n; i++) {
            std::vector<int> map(n+1, 0);
            for (int j = 0; j < n; j++) {
                map[matrix[j][i]]++;
            }
            for (int j = 1; j <= n; j++) {
                if (map[j] == 0)
                    return false;
            }
        }

        return true;
    }
};