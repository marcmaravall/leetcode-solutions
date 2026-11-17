class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());
        const int n = points.size();
        int res = 0;
        for (int i = 0; i < n-1; i++) {
            res = std::max(res, points[i+1][0]-points[i][0]);
        }
        return res;
    }
};