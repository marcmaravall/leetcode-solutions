class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbors = 0;
                if (i != 0 && board[i-1][j] % 2 == 1)
                    neighbors++;
                if (i != n-1 && board[i+1][j] % 2 == 1)
                    neighbors++;
                if (j != 0 && board[i][j-1] % 2 == 1)
                    neighbors++;
                if (j != m-1 && board[i][j+1] % 2 == 1)
                    neighbors++;
                    
                if (i != 0 && j != 0 && board[i-1][j-1] % 2 == 1)
                    neighbors++;
                if (i != n-1 && j != 0 && board[i+1][j-1] % 2 == 1)
                    neighbors++;
                if (i != 0 && j != m-1 && board[i-1][j+1] % 2 == 1)
                    neighbors++;
                if (i != n-1 && j != m-1 && board[i+1][j+1] % 2 == 1)
                    neighbors++;

                // 
                bool living = board[i][j] % 2 == 1;

                if (neighbors < 2 && living)
                    board[i][j] = 1;
                else if (neighbors <= 3 && living)
                    board[i][j] = 3;
                else if (neighbors > 3 && living)
                    board[i][j] = 1;
                else if (neighbors == 3 && !living)
                    board[i][j] = 2;
                else if (!living)
                    board[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = board[i][j] >= 2;
            }
        }
    }
};