class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        std::vector<std::vector<int>> res;

        const int target = graph.size()-1;
        std::function<void(std::vector<int>&, int)> dfs = 
            [&](std::vector<int>& vec, int current) {
            if (current == target) {
                res.push_back(vec);
                return;
            }

            for (int node : graph[current]) {
                vec.push_back(node);
                dfs(vec, node);
                vec.pop_back();
            }
        };

        std::vector<int> vec { 0 };
        dfs(vec, 0);

        return res;
    }
};