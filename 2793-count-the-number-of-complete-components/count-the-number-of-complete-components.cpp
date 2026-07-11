class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        std::bitset<51> visited;
        int res = 0;

        for (int i = 0; i < n; i++) {
            bool state = visited.test(i);

            if (!state) {
                int V = 0, D = 0;

                auto dfs = [&](auto& self, int x) -> void {
                    V++;
                    D += graph[x].size();
                    visited.set(x);

                    for (auto& state : graph[x])
                        if (!visited.test(state))
                            self(self, state);
                };

                dfs(dfs, i);

                res += D == V * (V - 1);
            }
        }

        return res;
    }
};