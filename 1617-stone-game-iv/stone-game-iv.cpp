class Solution {
public:
    inline bool perfectSquare(int n) {
        int root = std::sqrt(n);
        return root*root == n;
    }

    bool winnerSquareGame(int n) {
        std::vector<bool> dp(n+1);
        std::vector<int> moves { 1 };
        dp[1] = true;
        for (int i = 2; i <= n; i++) {
            if (perfectSquare(i)) {
                dp[i] = true;
                moves.push_back(i);
                continue;
            }
            for (int move : moves) {
                if (!dp[i-move])
                    dp[i] = true;
            }
        }
        return dp[n];
    }
};