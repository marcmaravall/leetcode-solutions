class Solution {
public:
    int dp(std::vector<std::vector<int>>& table, int s, int e) {
        if (s >= e)
            return 0;
        if (table[s][e] != 0)
            return table[s][e];
        int res = INT_MAX;
        for (int x = s; x <= e; x++) {
            int current = x + std::max(dp(table, s, x-1), dp(table, x+1, e));
            res = std::min(res, current);
        }
        table[s][e] = res;
        return res;
    }

    int getMoneyAmount(int n) {
        std::vector<std::vector<int>> table(n+1, std::vector<int>(n+1, 0));
        return dp(table, 1, n);
    }
};