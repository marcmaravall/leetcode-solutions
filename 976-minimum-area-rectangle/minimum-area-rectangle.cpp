class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        std::unordered_map<int, std::unordered_set<int>> map;
        for (auto& point : points)
            map[point[0]].insert(point[1]);
        int res = INT_MAX;
        const int n = points.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 != x2 && y1 != y2) {
                    if (map[x1].find(y2) != map[x1].end() && map[x2].find(y1) != map[x2].end()) {
                        res = std::min(res, std::abs((x1-x2) * (y1-y2)));
                    }
                }
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};