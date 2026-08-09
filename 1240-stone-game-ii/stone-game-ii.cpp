class Solution {
public:
    std::unordered_map<int, int> memo;

    int dfs(int i, int m, std::vector<int>& piles) {
        const int n = piles.size();
        if (i+2*m >= n)
            return piles[i];
        int key = (i << 8) | m;
        if (memo.count(key))
            return memo[key];
        int res = INT_MAX;
        for (int j = 1; j <= 2*m; j++) {
            res = std::min(res, dfs(i+j, std::max(m, j), piles));
        }
        res = piles[i] - res;
        memo[key] = res;
        return res;
    }

    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        for (int i = n-2; i >= 0; i--)
            piles[i] += piles[i+1];
        return dfs(0, 1, piles);
    }
};