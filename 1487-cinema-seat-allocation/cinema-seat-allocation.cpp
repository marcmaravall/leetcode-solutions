class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 2*n;
        std::unordered_map<int, std::array<bool, 11>> map;
        for (auto& seat : reservedSeats) {
            map[seat[0]][seat[1]] = true;
        }

        for (auto[row, seats] : map) {
            int removes = 0;
            if (seats[2] || seats[3] || seats[4] || seats[5]) {
                res--;
                removes++;
            }
            if (seats[6] || seats[7] || seats[8] || seats[9]) {
                res--;
                removes++;
            }
            if (removes == 2 && !seats[4] && !seats[5] && !seats[6] && !seats[7]) {
                res++;
            }
        }

        return res;
    }
};