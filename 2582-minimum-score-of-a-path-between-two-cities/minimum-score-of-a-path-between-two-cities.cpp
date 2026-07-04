class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        std::vector<int> root(n+1);
        std::iota(root.begin(), root.end(), 0);

        auto find = [&](this auto& self, int i) -> int {
            return root[i] == i ? i : self(root[i]);
        };

        for (auto& r : roads)
            root[find(r[0])] = find(r[1]);
        
        int res = INT_MAX;
        for (auto& r : roads)
            if (find(r[0]) == find(1))
                res = min(res, r[2]);
        return res;
    }
};