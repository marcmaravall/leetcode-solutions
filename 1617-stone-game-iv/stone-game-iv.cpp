#define MAX 100000
bool dp[MAX+1];
std::vector<int> moves;

class Solution {
public:
    static inline bool perfectSquare(int n) {
        int root = std::sqrt(n);
        return root*root == n;
    }

    inline static bool init = []() {
        moves = { 1 };
        dp[1] = true;
        for (int i = 2; i <= MAX; i++) {
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
        return true;
    }();

    bool winnerSquareGame(int n) {
        return dp[n];
    }
};