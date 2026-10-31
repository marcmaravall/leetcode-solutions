class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        std::sort(coordinates.begin(), coordinates.end());
        double xDiff = coordinates[0][0]-coordinates[1][0],
               yDiff = coordinates[0][1]-coordinates[1][1];
        double der = xDiff/yDiff;
        const int n = coordinates.size();
        for (int i = 1; i < n-1; i++) {
            double x = coordinates[i][0]-coordinates[i+1][0];
            double y = coordinates[i][1]-coordinates[i+1][1];
            if (x / y != der) {
                return false;
            }
        }
        return true;
    }
};