class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        std::array<int, 3> xyz;
        xyz[0] = x, xyz[1] = y, xyz[2] = z;
                                                            // dx, dy, dz
        std::unordered_map<int, std::pair<std::vector<int>, std::array<int, 3>>> graph;

        for (const auto& edge : edges) {
            const int u = edge[0], v = edge[1];
            graph[u].first.push_back(v);
            graph[v].first.push_back(u);
            for (int i = 0; i < 3; i++) {
                graph[u].second[i] = INT_MAX;
                graph[v].second[i] = INT_MAX;
            }
        }

        auto propagate = [&graph](int node, int index) {
            std::queue<int> q;
            std::unordered_map<int, bool> memo;
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
        for (const auto& [node, connections] : graph) {
            int dx = connections.second[0]-1, dy = connections.second[1]-1, dz = connections.second[2]-1;
            std::array<long long, 3> vec = {dx, dy, dz};
            std::sort(vec.begin(), vec.end());
            res += (vec[0]*vec[0] + vec[1]*vec[1] == vec[2]*vec[2]);
        }
        return res;
    }
};