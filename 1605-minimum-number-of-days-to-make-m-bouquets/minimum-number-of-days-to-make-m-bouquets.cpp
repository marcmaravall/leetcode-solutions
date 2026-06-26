class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        const int n = bloomDay.size();
        if ((long long)m*k > n)
            return -1;

        std::function<bool(int)> possible = [&](int days) {
            int c = 0;
            int b = 0;

            for(int i = 0; i < n; i++) {
                if (bloomDay[i] <= days)
                    c++;
                else {
                    b += c/k;
                    c = 0;
                }
            }

            b += c/k;
            return b >= m;
        };

        int left = *std::min_element(bloomDay.begin(), bloomDay.end());
        int right = *std::max_element(bloomDay.begin(), bloomDay.end());
        
        while (left < right) {
            int mid = (right+left)/2;
            if (possible(mid))
                right = mid;
            else 
                left = mid+1;
        }

        return left;
    }
};