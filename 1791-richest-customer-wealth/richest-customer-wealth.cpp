class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for (auto& account : accounts) {
            int cur = 0;
            for (int m : account)
                cur += m;
            res = std::max(res, cur);
        }
        return res;
    }
};