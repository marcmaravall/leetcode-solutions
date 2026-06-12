class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        std::vector<int> res(n, 0);

        for (auto& a : matrix) {
            for (int i = 0; i < n; i++) {
                if (a[i] == 1)
                    res[i]++;
            }
        }

        return res;
    }
};