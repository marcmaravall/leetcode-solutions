class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto possible = [&](long long k) {
            long long a = 0;

            for (int b : quantities) {
                a += (b+k-1) / k;
                if (a > n)
                    return false;
            }

            return true;
        };

        long long left = 1;
        long long right = std::accumulate(quantities.begin(), quantities.end(), 0LL);

        while (left < right) {
            long long mid = (left+right)/2;
            if (possible(mid)) {
                right = mid;
            } else left = mid+1;
        }

        return left;
    }
};