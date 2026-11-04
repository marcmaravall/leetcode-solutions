class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0;
        auto valid = [&](int i, int j, int size) -> bool {
            return !(i+size >= n || j+size >= n || i-size < 0 || j-size < 0);
        };
        std::vector<std::vector<bool>> grid(n, std::vector<bool>(n, true));
        for (const auto& m : mines) {
            grid[m[0]][m[1]] = false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int cur = 0;
                for (int k = 0; valid(i, j, k); k++) {
                    if (!grid[i+k][j] || !grid[i-k][j] ||
                        !grid[i][j+k] || !grid[i][j-k]) {
                        break;
                    }
                    cur++;
                }
                res = std::max(res, cur);
            }
        }
        return res;
    }
};