class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        std::sort(asteroids.begin(), asteroids.end());
        uint64_t mass64 = mass;

        for (int asteroid : asteroids) {
            if (asteroid > mass64) 
                return false;
            mass64 += asteroid;
        }

        return true;
    }
};