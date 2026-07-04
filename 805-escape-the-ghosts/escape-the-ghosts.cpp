class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int distance = std::abs(target[0]) + std::abs(target[1]);
        for (auto& g : ghosts) {
            int ghostDistance = std::abs(g[0] - target[0]) + std::abs(g[1]-target[1]);
            if (ghostDistance <= distance)
                return false;
        }
        return true;
    }
};