class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int smallest = INT_MAX;
        int res = -1;
        const int n = points.size();
        for (int i = 0; i < n; i++) {
            int dist = std::abs(x-points[i][0])+std::abs(y-points[i][1]);
            if ((x == points[i][0] || y == points[i][1]) && dist < smallest) {
                smallest = dist;
                res = i;
            }
        }
        return res;
    }
};