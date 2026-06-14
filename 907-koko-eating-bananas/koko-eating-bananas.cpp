class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto canEat = [&](long long k) {
            long long hours = 0;

            for (int b : piles) {
                hours += (b + k - 1) / k;

                if (hours > h)
                    return false;
            }

            return true;
        };

        long long left = 1;
        long long right = std::accumulate(piles.begin(), piles.end(), 0LL);

        while (left < right) {
            long long mid = (left+right)/2;
            if (canEat(mid)) {
                right = mid;
            } else left = mid+1;
        }

        return left;
    }
};