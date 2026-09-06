class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        std::vector<std::vector<int>> res;
        bool hasQueen[65] = {};
        for (auto& queen : queens) {
            hasQueen[queen[0]+queen[1]*8] = true;
        }
        const int xKing = king[0], yKing = king[1];
        for (int x = xKing+1; x < 8; x++) {
            if (hasQueen[x+8*yKing]) {
                res.push_back({x, yKing});
                break;
            }
        }
        for (int x = xKing-1; x >= 0; x--) {
            if (hasQueen[x+8*yKing]) {
                res.push_back({x, yKing});
                break;
            }
        }
        for (int y = yKing+1; y < 8; y++) {
            if (hasQueen[xKing+8*y]) {
                res.push_back({xKing, y});
                break; 
            }
        }
        for (int y = yKing-1; y >= 0; y--) {
            if (hasQueen[xKing+8*y]) {
                res.push_back({xKing, y});
                break;
            }
        }
        
        for (int i = 1; i+std::max(xKing, yKing) < 8; i++) {
            int x = xKing+i;
            int y = yKing+i;
            if (hasQueen[x+8*y]) {
                res.push_back({x, y});
                break;
            }
        }
        for (int i = 1; std::min(xKing, yKing)-i >= 0; i++) {
            int x = xKing-i;
            int y = yKing-i;
            if (hasQueen[x+8*y]) {
                res.push_back({x, y});
                break;
            }
        }

        for (int i = 1; xKing-i >= 0 && yKing+i < 8; i++) {
            int x = xKing-i;
            int y = yKing+i;
            if (hasQueen[x+8*y]) {
                res.push_back({x, y});
                break;
            }
        }
        for (int i = 1; xKing+i < 8 && yKing-i >= 0; i++) {
            int x = xKing+i;
            int y = yKing-i;

            if (hasQueen[x+8*y]) {
                res.push_back({x, y});
                break;
            }
        }

        return res;
    }
};