class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        std::vector<int> res(n, 0);
        for (const auto& booking : bookings) {
            for (int i = booking[0]; i <= booking[1]; i++) {
                res[i-1] += booking[2];
            }
        }
        return res;
    }
};