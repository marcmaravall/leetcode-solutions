class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int n = rooms.size();
        std::vector<bool> visited(n, false);
        visited[0] = true;

        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int current = q.front();
                q.pop();

                for (int key : rooms[current]) {
                    if (!visited[key]) {
                        q.push(key);
                        visited[key] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i])
                return false;
        }
        return true;
    }
};