class Solution {
public:
    inline bool inside(const std::vector<int>& query, const std::vector<int>& point) {
        return sqrt(pow(point[0] - query[0], 2) + pow(point[1] - query[1], 2)) <= query[2]; 
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            int current = 0;
            for (int j = 0; j < points.size(); j++) {
                if (inside(queries[i], points[j])) {
                    current++;
                }
            }
            res[i] = current;
        }

        return res;
    }
};