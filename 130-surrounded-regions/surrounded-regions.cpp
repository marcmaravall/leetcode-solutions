class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int n = board.size(), m = board[0].size();
        std::function<bool(int, int, std::unordered_map<int, bool>&)> surronded = [&](int y, int x, std::unordered_map<int, bool>& memo){
            if (board[y][x] == 'X')
                return true;
            
            if (y == 0 || x == 0 || y == n-1 || x == m-1)
                return false;
            
            int hash = y << 16 | x;
            if (memo.contains(hash))
                return memo[hash];
            memo[hash] = true;
            
            bool res = surronded(y+1, x, memo) &&
                      surronded(y, x+1, memo) && 
                      surronded(y-1, x, memo) &&
                      surronded(y, x-1, memo);
            return res;
        };

        std::function<void(int, int)> fill = [&](int y, int x) {
            if (y < 0 || x < 0 || y >= n || x >= m || board[y][x] == 'X')
                return;
            board[y][x] = 'X';
            fill(y, x+1);
            fill(y, x-1);
            fill(y+1, x);
            fill(y-1, x);
        };
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::unordered_map<int, bool> memo;
                if (board[i][j] == 'O' && surronded(i, j, memo)) {
                    fill(i, j);
                }
            }
        }
    }
};