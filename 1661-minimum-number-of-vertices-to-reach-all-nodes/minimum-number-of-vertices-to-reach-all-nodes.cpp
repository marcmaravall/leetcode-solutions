class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<bool> v(n, 0);
        for (auto& e : edges) {
            v[e[1]] = true;
        }

        std::vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!v[i])
                res.push_back(i);
        }

        return res;
    }
};