struct A {
    int x, y;
    int h = 0;
    
    A(int _x, int _y, int _h) : x(_x), y(_y), h(_h) {}
    ~A() = default;
    
    bool operator==(const A& other) const {
        return x == other.x && y == other.y && h == other.h;
    }
};

namespace std {
    template <>
    struct hash<A> {
        std::size_t operator()(const A& k) const {
            std::size_t h1 = std::hash<int>{}(k.x);
            std::size_t h2 = std::hash<int>{}(k.y);
            std::size_t h3 = std::hash<int>{}(k.h);
            
            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };
}

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        const int n = grid.size();
        const int m = grid[0].size();

        std::vector<std::vector<int>> best(n, std::vector<int>(m, -1));
        std::queue<A> q;
        q.push(A(0, 0, health));

        while (!q.empty()) {
            size_t s = q.size();
            for (int i = 0; i < s; i++) {
                auto pos = q.front();
                q.pop();
                if (grid[pos.y][pos.x] == 1)
                    pos.h--;

                if (pos.x == m-1 && pos.y == n-1 && pos.h > 0)
                    return true;
                else if (pos.h <= 0 || pos.h <= best[pos.y][pos.x])
                    continue;
                best[pos.y][pos.x] = std::max(best[pos.y][pos.x], pos.h);

                if (pos.x > 0) q.push(A(pos.x-1, pos.y, pos.h));
                if (pos.x < m-1) q.push(A(pos.x+1, pos.y, pos.h));
                if (pos.y > 0) q.push(A(pos.x, pos.y-1, pos.h));
                if (pos.y < n-1) q.push(A(pos.x, pos.y+1, pos.h));
            }
        }

        return false;
    }
};