class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        std::vector<int> degree(n, 0);
        std::vector<std::vector<bool>> connected(n, std::vector<bool>(n, false));
        const int s = roads.size();
        for (int i = 0; i < s; i++) {
            int u = roads[i][0], v = roads[i][1];
            degree[u]++;
            degree[v]++;
            connected[u][v] = true;
            connected[v][u] = true;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j=i+1; j < n; j++) {
                int curr = degree[i] + degree[j] - connected[i][j];
                res = std::max(res, curr);
            }
        }
        return res;
    }
};