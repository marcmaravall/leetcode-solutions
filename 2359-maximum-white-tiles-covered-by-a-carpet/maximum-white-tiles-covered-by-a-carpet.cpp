class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        std::sort(tiles.begin(), tiles.end());
        const int n = tiles.size();
        int res = 0;
        long long covered = 0;
        int j = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && tiles[j][1]-tiles[i][0]+1 <= carpetLen) {
                covered += tiles[j][1]-tiles[j][0]+1;
                j++;
            }

            res = std::max(res, (int)covered);
            if (j < n) {
                int carpetEnd = tiles[i][0]+carpetLen-1;
                if (carpetEnd >= tiles[j][0]) {
                    int partial = carpetEnd-tiles[j][0]+1;
                    res = std::max(res, (int)covered+partial);
                }
            }
            covered -= tiles[i][1]-tiles[i][0]+1;
        }
        return res;
    }
};
