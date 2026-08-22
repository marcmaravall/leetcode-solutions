class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int oCount = 0;
        int xCount = 0;

        for (auto& str : board)
            for (char c : str)
                if (c == 'X')
                    xCount++;
                else if (c == 'O')
                    oCount++;

        if (oCount > xCount || xCount-oCount > 1)
            return false;

        int xWins = 0;
        int oWins = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && 
                board[i][0] == board[i][1] && board[i][0] == board[i][2])
                if (board[i][0] == 'X')
                    xWins++;
                else oWins++;
            if (board[0][i] != ' ' && 
                board[0][i] == board[1][i] && board[0][i] == board[2][i])
                if (board[0][i] == 'X')
                    xWins++;
                else oWins++;
        }
        if (board[0][0] != ' ' && 
            board[0][0] == board[1][1] && board[1][1] == board[2][2])
            if (board[0][0] == 'X')
                xWins++;
            else oWins++;
        if (board[0][2] != ' ' && 
            board[0][2] == board[1][1] && board[1][1] == board[2][0])
            if (board[0][2] == 'X')
                xWins++;
            else oWins++;
        
        if ((xWins && oWins) || 
            (xWins && xCount == oCount) || (oWins && oCount < xCount))
            return false;
        return true;
    }
};