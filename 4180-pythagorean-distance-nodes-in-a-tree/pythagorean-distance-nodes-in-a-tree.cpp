class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        std::array<int, 3> xyz;
        xyz[0] = x, xyz[1] = y, xyz[2] = z;
                                                            // dx, dy, dz
        std::vector<std::pair<std::vector<int>, std::array<int, 3>>> graph(n);

        for (const auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            graph[u].first.push_back(v);
            graph[v].first.push_back(u);
            for (int i = 0; i < 3; i++) {
                graph[u].second[i] = INT_MAX;
                graph[v].second[i] = INT_MAX;
            }
        }

        auto propagate = [&](int node, int index) {
            std::queue<int> q;
            std::vector<bool> memo(n);
            q.push(node);
            memo[node] = true;
            for (int distance = 1; !q.empty(); distance++) {
                int size = q.size();
                for (int i = 0; i < size; i++) {
                    int curr = q.front();
                    q.pop();
                    memo[curr] = true;
                    graph[curr].second[index] = distance;
                    for (int a : graph[curr].first) {
                        if (!memo[a]) {
                            q.push(a);
                        }
                    }
                }
            }
        };

        for (int i = 0; i < 3; i++) {
            propagate(xyz[i], i);
        }

        int res = 0;
        for (const auto& connections : graph) {
            const long long dx = connections.second[0]-1, dy = connections.second[1]-1, dz = connections.second[2]-1;
            const long long asq = dx*dx, bsq = dy*dy, csq = dz*dz;
            res += (asq+bsq == csq || asq+csq == bsq || bsq+csq == asq);
        }
        return res;
    }
};