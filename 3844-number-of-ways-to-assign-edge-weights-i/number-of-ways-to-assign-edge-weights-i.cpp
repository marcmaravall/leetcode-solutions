class Solution {
public:
    long long pow(long long base, int exp) {
        constexpr int mod = 1000000007;
        long long res = 1;

        while (exp) {
            if (exp % 2 == 1)
                res = res * base % mod;

            base = base * base % mod;
            exp /= 2;
        }

        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size();
        std::vector<std::vector<int>> graph(edges.size()+2);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int k = 0;
        auto dfs = [&](this auto&& dfs, int node, int prev) -> int {
            int res = 0;

            for (auto& x : graph[node])
                if (x != prev)
                    res = max(res, dfs(x, node) + 1);

            return res;
        };
        k = dfs(1, 0);

        return pow(2, k-1);
    }
};