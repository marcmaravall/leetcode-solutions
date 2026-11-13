class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int n = points.size();
        std::vector<bool> visited(n, false);
        int res = 0;
        std::priority_queue<std::pair<int, int>> pqueue;
        int i = 0;
        for (int connected = 1; connected < n; connected++) {
            visited[i] = true;
            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    int dist = std::abs(points[i][0]-points[j][0])+std::abs(points[i][1]-points[j][1]);
                    pqueue.push({-dist, j});
                }
            }
            while (visited[pqueue.top().second]) {
                pqueue.pop();
            }
            res -= pqueue.top().first;
            i = pqueue.top().second;
            pqueue.pop();
        }
        return res;
    }
};