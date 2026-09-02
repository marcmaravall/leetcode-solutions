class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        const int n = timePoints.size();
        std::vector<int> minutes(n);
        for (int i = 0; i < n; i++) {
            int mins = static_cast<int>(timePoints[i][4]-'0' + 10*(int)(timePoints[i][3]-'0'));
            int hours = static_cast<int>(timePoints[i][1]-'0' + 10*(timePoints[i][0]-'0'));
            minutes[i] = mins + hours*60;
        }
        std::sort(minutes.begin(), minutes.end());
        const int day = 24*60;
        int res = minutes[0]+day-minutes[n-1];
        for (int i = 0; i < n-1; i++) {
            int diff = minutes[i+1]-minutes[i];
            res = std::min({res, diff});
        }
        return res;

    }
};