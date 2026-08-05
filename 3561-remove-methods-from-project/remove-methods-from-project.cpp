class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        std::vector<std::vector<int>> graph(n);

        for (auto &e : invocations)
            graph[e[0]].push_back(e[1]);

        std::vector<bool> suspicious(n, false);
        std::queue<int> q;
        q.push(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (suspicious[u]) continue;
            suspicious[u] = true;

            for (int v : graph[u])
                q.push(v);
        }

        for (auto &e : invocations) {
            int u = e[0], v = e[1];
            if (!suspicious[u] && suspicious[v]) {
                std::vector<int> res;
                for (int i = 0; i < n; i++)
                    res.push_back(i);
                return res;
            }
        }

        std::vector<int> res;
        for (int i = 0; i < n; i++)
            if (!suspicious[i])
                res.push_back(i);

        return res;
    }
};