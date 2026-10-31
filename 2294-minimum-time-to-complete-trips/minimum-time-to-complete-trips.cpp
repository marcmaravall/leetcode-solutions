class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        auto can = [&](long long t) -> bool {
            int trips = 0;
            for (int bus : time) {
                trips += t/bus;
                if (trips >= totalTrips)
                    return true;
            }
            return false;
        };
        long long left = 0, right = *std::min_element(time.begin(), time.end())*(long long)totalTrips;
        while (left < right) {
            long long mid = (left+right)/2;
            if (can(mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};