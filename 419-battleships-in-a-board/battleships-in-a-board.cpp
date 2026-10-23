class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const int n = board.size(), m = board[0].size();
        int res = 0;
        auto propagate = [&](int y, int x) {
            for (int i = y+1; i < n; i++) {
                if (board[i][x] != 'X')
                    break;
                board[i][x] = '.';
            }
            for (int i = x; i < m; i++) {
                if (board[y][i] != 'X')
                    break;
                board[y][i] = '.';
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    res++;
                    propagate(i, j);
                }
            }
        }
        return res;
    }
};