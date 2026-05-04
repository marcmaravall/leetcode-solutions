class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::vector<std::vector<int>> res;
        std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
        });

        for (int i = 0; i < k; i++) {
            res.push_back(points[i]);
        }
        return res;
    }
};