class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int orig = image[sr][sc];

        std::vector<std::vector<bool>> visited(n);
        for (int i = 0; i < n; i++) {
            visited[i].resize(m);
            for (int j = 0; j < m; j++) {
                visited[i][j] = false;
            }
        }

        std::function<void(int x, int y)> propagate = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= m || y >= n || image[y][x] != orig || visited[y][x]) {
                return;
            }
            
            image[y][x] = color;
            visited[y][x] = true;

            propagate(x+1, y);
            propagate(x-1, y);
            propagate(x, y+1);
            propagate(x, y-1);
        };

        propagate(sc, sr);

        return image;
    }
};