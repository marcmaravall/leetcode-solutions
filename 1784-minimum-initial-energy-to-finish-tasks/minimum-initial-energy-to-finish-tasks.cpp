class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        std::sort(tasks.begin(), tasks.end(), [](std::vector<int>& a, std::vector<int>& b) {
            return (a[1]-a[0]) > (b[1]-b[0]);
        });
        int res = 0;
        int cost = 0;
        for (std::vector<int>& task : tasks) {
            res += cost > task[1] ? 0 : task[1] - cost;
            cost = max(task[1] - task[0], cost - task[0]);
        }

        return res;
    }
};