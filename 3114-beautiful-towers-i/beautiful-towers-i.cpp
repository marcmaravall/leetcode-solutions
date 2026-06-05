class Solution {
public:
    long long maximumSumOfHeights(vector<int>& heights) {
        const int n = heights.size();
        long long res = 0;

        for (int i = 0; i < heights.size(); i++) {
            long long current = heights[i];
            long long last = heights[i];

            for (int j = i-1; j >= 0; j--) {
                if (heights[j] <= last) {
                    last = heights[j];
                }
                current += last;
            }

            last = heights[i];
            for (int j = i+1; j < n; j++) {
                if (heights[j] <= last) {
                    last = heights[j];    
                }
                current += last;
            }

            res = max(res, current);
        }

        return res;
    }
};