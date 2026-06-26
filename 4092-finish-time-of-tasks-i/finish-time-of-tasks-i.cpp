class Solution {
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        std::vector<std::vector<int>> graph(n, std::vector<int>());
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }

        std::function<long long(int)> ft = [&](int node) -> long long {
            if (graph[node].empty())
                return baseTime[node];

            long long earliest = LONG_MAX;
            long long latest = LONG_MIN;
            for (int child : graph[node]) {
                long long val = ft(child);
                earliest = min(earliest, val);
                latest = max(latest, val);
            }

            return 2*latest-earliest + baseTime[node];
        };

        return ft(0);
    }
};