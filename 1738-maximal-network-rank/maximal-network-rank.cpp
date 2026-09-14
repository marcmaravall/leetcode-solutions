class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::array<std::vector<int>, 101> graph;
        for (auto& road : roads) {
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        int res = 0;
        for (int i = 0; i < 101; i++) {
            if (graph[i].empty())
                continue;
            std::unordered_map<int, bool> map;
            int containing = 0;
            for (int x : graph[i]) {
                map[i << 16 | x] = true;
                containing++;
            }
            for (int j = i+1; j < 101; j++) {
                if (graph[j].empty())
                    continue;
                int curr = containing;
                for (int x : graph[j]) {
                    if (!map[j << 16 | x] && !map[x << 16 | j]) {
                        curr++;
                    }
                }
                res = std::max(res, curr);
            }
        }
        return res;
    }
};