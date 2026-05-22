class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char current = board[i][j];
                if (current == '.')
                    continue;

                for (int k = 0; k < 9; k++) {
                    if (board[i][k] == current && k != j)
                        return false;
                    if (current == board[k][j] && k != i)
                        return false;
                }

                int sqY = i < 3 ? 0 : (i < 6 ? 3 : 6);
                int sqX = j < 3 ? 0 : (j < 6 ? 3 : 6);
                for (int ii = sqY; ii < sqY + 3; ii++) {
                    for (int jj = sqX; jj < sqX + 3; jj++) {
                        if (ii == i && jj == j)
                            continue;
                        if (board[ii][jj] == current)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};