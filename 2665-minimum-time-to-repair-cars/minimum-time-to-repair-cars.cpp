class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = (long long)*std::min_element(ranks.begin(), ranks.end()) * cars*cars;

        auto canRepair = [&](long long time) -> bool {
            int repaired = 0;
            for (int r : ranks) {
                repaired += sqrt(time/r);
                if (repaired >= cars) {
                    return true;
                }
            }

            return false;
        };

        while (left < right) {
            long long mid = (left + right) / 2;
            if (canRepair(mid)) {
                right = mid;
            } else
                left = mid+1;
        }

        return right;
    }
};
