class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        const int n = plants.size();
        int res = 0;
        int water = capacity;
        for (int i = 0; i < n; i++) {
            water -= plants[i];
            if (i < n-1 && water-plants[i+1] < 0) {
                res += 2*i+2;
                water = capacity;
            }
            res++;
        }
        return res;
    }
};