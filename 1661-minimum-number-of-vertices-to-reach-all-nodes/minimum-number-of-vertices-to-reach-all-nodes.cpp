class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[1]].push_back(e[0]);
        }

        std::unordered_set<int> uset;
        std::function<int(int)> parent = [&](int node) {
            if (graph[node].size() == 0)
                return node;
            return parent(graph[node][0]);
        };

        for (auto& e : edges) {
            uset.emplace(parent(e[0]));
        }
        std::vector<int> res(uset.begin(), uset.end());
        return res;
    }
};