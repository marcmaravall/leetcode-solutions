class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        const int sx = source[0], sy = source[1];
        const int tx = target[0], ty = target[1];
        if ((sx+sy) % 2 != (tx+ty) % 2)
            return -1;
        if (sx == tx && sy == ty)
            return 0;
        if (std::abs(sx-tx) == std::abs(sy-ty))
            return 1;
        return 2;
    }
};